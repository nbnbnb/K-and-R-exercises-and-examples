/* Write the function itob(n,s,b) that converts the integer n into a base b character
   represeintation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal
   integer in s.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100

// 3.6 do-while 循环
// itob 函数将 10 进制数值转换为 16 进制字符

// 将 15 转换为 f
// 将 -15 转换为 -f

void itob(int n, char s[], int base);
void reverse(char s[]);

int main()
{
  int n = 15;
  char s[MAXLEN];

  itob(n, s, 16);
  printf("%s\n", s);

  return 0;
}

/* itob: convert n to a string s representing n in base b */
void itob(int n, char s[], int b)
{
  int i, sign, num;

  sign = n;
  n = abs(n); // sets n to be positive
  i = 0;

  // 转换为 16 进制
  do
  {
    // generate digits in reverse order
    // 第一步是取模，得到最后的一个整数值
    num = n % b;

    if (num < 10)
    {
      s[i++] = num + '0';
    }
    else
    {
      s[i++] = num - 10 + 'a';
    }
  } while ((n /= b) > 0); // 然后每一步取余，在到 do 循环中取模

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
