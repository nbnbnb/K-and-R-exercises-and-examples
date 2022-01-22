#include <stdio.h>

// 6.2 结构与函数

#define XMAX 100
#define YMAX 100
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

// 定义一个结构
// 注意结尾的 ;
struct point
{
  int x;
  int y;
};

// 定义一个结构
// 注意结尾的 ;
struct rect
{
  struct point pt1;
  struct point pt2;
};

// 声明返回结构的函数
struct point makepoint(int x, int y);

// 声明返回结构的函数
// 参数也是结构
struct point addpoint(struct point p1, struct point p2);

// 声明返回结构的函数
// 参数也是结构
int ptinrect(struct point p, struct rect r);

int main(void)
{
  // 声明结构变量
  struct rect screen;
  struct point middle;
  struct point origin;

  // 这是一个结构指针
  struct point *pp;

  // 设置结构变量的值
  screen.pt1 = makepoint(0, 0);

  // 设置结构变量的值
  screen.pt2 = makepoint(XMAX, YMAX);

  // 读取结构变量
  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);

  origin = screen.pt1;

  // 取结构的指针
  pp = &origin;

  // 取指针的值 - 写法 01
  printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);

  // 取指针的值 - 写法 02
  printf("origin is (%d,%d)\n", pp->x, pp->y);

  return 0;
}

/* makepint: make a point from x and y components */
struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

/* addpoint: add two points*/
struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectanglw */
struct rect canonrect(struct rect r)
{
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);

  return temp;
}
