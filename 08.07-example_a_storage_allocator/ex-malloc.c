#include <stdlib.h>
#include <string.h>

// 8.7 实例 —— 存储分配程序

// 为了简化块的对齐，所有块的大小都必须是头部大小的 "整数倍"
// 且头部已正确对齐

/**
 * 确保由 malloc 函数返回的存储空间满足将要保存的对象的对齐要求
 * 
 * 虽然机器类型各异，但是每个特定的机器都有一个 "最受限" 的类型
 * 如果 "最受限" 的类型可以存储在某个特定的地址中，则其它所有的类型也可以存放在此地址中
 * 
 * 在某些机器中，最受限的类型是 double，另一些机器中，最受限的类型是 int 或 long
 * 
 */

// 假定 long 类型为最受限的类型
typedef long Align; // for alignment to long boundary

union header // block header:
{
  struct
  {
    // 指向链表下一个块的指针
    union header *ptr;
    // 块的大小
    unsigned size;
  } s;

  // 这个字段永远不会使用
  // 仅仅用于强制每个头部在最坏的情况下满足对齐要求
  Align x;
};

typedef union header Header;

static Header base;          // empty list to get started with
static Header *freep = NULL; // start of free list
void *malloc(unsigned nbytes);

/* malloc: general-purpose storage allocator */

// malloc 管理的空间不一定是连续的
// 空闲存储空间以空闲块链表的方式组织
void *malloc(unsigned nbytes)
{
  Header *p, *prevp;

  Header *morecore(unsigned);

  unsigned nunits;

  // 请求的长度（以字符为单位）被舍入
  // 保证它是头部大小的整数倍
  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

  if ((prevp = freep) == NULL) // no free list yet
  {
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }

  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr)
  {
    if (p->s.size >= nunits) // big enough
    {
      if (p->s.size == nunits) // exactly
      {
        prevp->s.ptr = p->s.ptr;
      }
      else // allocate tail end
      {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }

      freep = prevp;

      return (void *)(p + 1);
    }

    if (p == freep) // wrapped around free list
    {
      if ((p = morecore(nunits)) == NULL)
      {
        return NULL; // none left
      }
    }
  }
}

#define NALLOC 1024 // minimum #units to request

/* morecore: ask system for more memory */
Header *morecore(unsigned nu)
{
  char *cp, *sbrk(int);

  Header *up;

  if (nu < NALLOC)
  {
    nu = NALLOC;
  }

  cp = sbrk(nu * sizeof(Header));

  if (cp == (char *)-1) // no space at all
  {
    return NULL;
  }

  up = (Header *)cp;

  up->s.size = nu;

  free((void *)(up + 1));

  return freep;
}

/* free: put block ap in free list */
void free(void *ap)
{
  Header *bp, *p;

  bp = (Header *)ap - 1; // point to block header

  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
  {
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    {
      break; // freed block at start of end of arena
    }
  }

  if (bp + bp->s.size == p->s.ptr) // join to upper
  {
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  }
  else
  {
    bp->s.ptr = p->s.ptr;
  }

  if (p + p->s.size == bp)
  {
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  }
  else
  {
    p->s.ptr = bp;
  }

  freep = p;
}
