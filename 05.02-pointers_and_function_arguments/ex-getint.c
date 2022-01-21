#include <stdio.h>

// 输入：1 23 4 5
// 输入：回车
// 输入：Ctrl+Z（Linux Ctrl+D）
// 输出：1 23 4 5

#define MAXLEN 1000

int getint(int *);

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

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getchar())) // skip whitespaces
    ;

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
  {
    c = getchar();
  }

  for (*pn = 0; isdigit(c); c = getchar())
  {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;

  return c;
}
