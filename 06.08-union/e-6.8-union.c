#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 6.8 联合

// 联合是可以（在不同时刻）保存不同类型和长度的对象的变量
// 编译器负责跟踪对象的长度和对齐要求

// 读取的类型必须与最近一次存入的类型一致

// 联合名.成员
// 联合指针->成员

// 联合只能用其第一个成员类型的值进行初始化

union u_tag
{
  /* data */
  int ival;
  float fval;
  char *sval;
} u1;

struct
{
  char *name;
  int flags;
  int utype;
  union
  {
    int ival;
    float fval;
    char *sval;
  } u;
} symtab[10];

int main(void)
{
  u1.ival = 100;

  printf("%d\n", u1.ival);

  return 0;
}
