#include <stdio.h>

// 5.4 地址算术符

// 输出：Allocated 4*10 bytes

// 指向 n 个连续字符存储单元的指针
// 注意，这个函数返回的是一个 “指针”
char *alloc(int n);
// char *alloc(int);

// 释放已分配的存储空间
void afree(char *p);
// void afree(char *);

int main()
{
  int n = 10;
  char *p;

  p = alloc(n);

  if (p)
  {
    printf("Allocated 4*%d bytes", n);
  }
  else
  {
    printf("Could not allocate!");
  }

  // 将指针向前移动 3 个 "位置"
  p = p - 3;

  // 即当前指针置为 p
  afree(p);

  return 0;
}

#define ALLOCSIZE 10000 // size of available space

// 声明为 static 类型，使得它对外不可见
// 分配一个固定空间的字符数组
static char allocbuf[ALLOCSIZE]; // storage for alloc
// 初始化：赋值数组的初始地址
static char *allocp = allocbuf; // next free

char *alloc(int n) // return pointter to n characters
{
  // allocbuf 是数组的初始地址
  // allocbuf + ALLOCSIZE 表示分配的 "结尾地址"
  // allocbuf + ALLOCSIZE - allocp 表示 "结尾地址" - "当前地址" = "可分配字符数"
  if (allocbuf + ALLOCSIZE - allocp >= n) // it fits
  {
    // 分配 n 个连续空间
    // 将 allocp 指向下个空闲单元
    allocp += n;
    // 返回 allocp 当前值
    return allocp - n; // old p
  }
  else // not enough room
  {
    // C 语言保证，0 永远不是有效的地址空间
    // 返回 0 可用来表示发生了异常事件

    // 指针与整数之间不能相互转换，但 0 是唯一的例外
    // 常量 0 可以赋值给指针，指针也可以和常量 0 进行比较

    // 空间不够，返回 0
    // return 0;

    // 程序中，经常用符号常量 NULL 代替常量 0，这样便于更清晰地说明常量 0 是指针的一个特殊值
    return NULL;
    // NULL 是一个宏
    // return ((void *)0);
  }
}

void afree(char *p) // free storage pointed to by p
{
  // 验证 p 在分配的范围之内
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
  {
    // 简单将当前指针置为 p
    allocp = p;
  }
}
