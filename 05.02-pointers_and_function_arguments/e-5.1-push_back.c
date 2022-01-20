/* As written, getint treats a + or - not followed by a digit as a valid representation
   of zero. Fix it to push such a character back to the input. */
#include <stdio.h>

// 5.2 指针与函数参数

// 输入：123 4 5 6 7 8
// 输入：回车
// 输入：Ctrl+Z（Linux Ctrl+D）
// 输出：123 4 5 6 7 8
// 数组中有 6 个元素

#define MAXLEN 1000

int getint(int *pn);
// 指针参数的函数，可以不带变量名称
// int getint(int *);

int main(void)
{
  int a[MAXLEN], n;

  //  &a[n] 传递的是指针
  for (n = 0; n < MAXLEN && getint(&a[n]) != EOF; n++)
    ;

  printf("\n");

  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\n");

  return 0;
}

#include <ctype.h>

// 每次调用 getint 时，输入流中的下一个整数将会被赋值给数组元素 array[n]
// 同时，n 的值将增加 1
/* getint: get next integer from input into *pn */
int getint(int *pn)
{
  int c, sign, prev = 0;

  while (isspace(c = getchar())) // skip whitespaces
    ;

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
  {
    c = getchar();
  }

  for (*pn = 0; isdigit(c); c = getchar())
  {
    // c - '0' 表示数值差
    // 从 10 开始乘
    // '123' 拆解
    // '1' -> 10 * 0  + 1 = 1
    // '2' -> 10 * 1  + 2 = 12
    // '3' -> 10 * 12 + 3 = 123
    // pn 最后指向的值就是 123
    *pn = 10 * *pn + (c - '0');
  }

  // 乘以 1 或者 -1
  *pn *= sign;

  return c;
}
