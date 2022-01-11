/* Test for a power function. */
// 1.7 函数
#include <stdio.h>

// 函数原型（参数名可选，而且也不需要与实现保持一致）
// 下面三种都是合法的
//int power(int, int);
//int power(int m, int n);
int power(int base, int n);

int main(void)
{
  int i;

  for (i = 0; i < 10; ++i)
  {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }

  return 0;
}

int power(int base, int n)
{
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
  {
    p = p * base;
  }

  return p;
}
