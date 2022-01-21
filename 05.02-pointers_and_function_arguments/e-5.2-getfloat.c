/* As written, getint treats a + or - not followed by a digit as a valid representation
   of zero. Fix it to push such a character back to the input. */
#include <stdio.h>

// 5.2 指针与函数参数

// 输入：12.34 4.5 6.7
// 输入：回车
// 输入：Ctrl+Z（Linux Ctrl+D）
// 输出：12.34 4.5 6.7

#define MAXLEN 1000

int getint(float *);

int main(void)
{
  float a[MAXLEN];
  int n;

  for (n = 0; n < MAXLEN && getint(&a[n]) != EOF; n++)
    ;

  printf("\n");

  for (int i = 0; i < n; i++)
  {
    printf("%g ", a[i]);
  }

  printf("\n");
  return 0;
}

#include <ctype.h>
#include <math.h>

/* getint: get next integer from input into *pn */
int getint(float *pn)
{
  int c, sign, prev = 0, j;
  float inte, frac;

  while (isspace(c = getchar())) // skip whitespaces
    ;

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
  {
    c = getchar();
  }

  for (inte = 0; isdigit(c); c = getchar())
  {
    inte = 10.0 * inte + (float)(c - '0');
  }

  if (c == '.')
  {
    c = getchar();

    for (frac = 0, j = 0; isdigit(c); c = getchar(), j++)
    {
      frac = 10.0 * frac + (float)(c - '0');
    }
  }

  *pn = ((float)sign) * (inte + frac / powf(10, j));

  return c;
}
