#include <stdio.h>
#include <string.h>

#define MAXLEN 100

// 3.6 do-while 循环
// itoa 函数是 atoi 函数的逆函数，将数字转换为字符串

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
  int n = 324;
  char s[MAXLEN];

  itoa(n, s);
  printf("%s\n", s);

  return 0;
}

/* itoa: convert n to characters on s */
void itoa(int n, char s[])
{
  int i, sign;

  // 不用 abs 函数
  // 的另一种写法
  // 转换为正数
  if ((sign = n) < 0) // record sign
  {
    n = -n; // make n positive
  }

  i = 0;

  do
  { // generate digits in reverse order
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

// 字符串反转
void reverse(char s[])
{
  int i, j;
  char c;

  // strlen 是 <string.h> 中的函数

  // 成对交换：i++, j--
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
