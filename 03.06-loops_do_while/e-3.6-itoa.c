/* Write a version of itoa that accepts three arguments instead of two. The third
   argument is the minimum field witdh; the converted number must be padded with 
   blanks on the left if necessary to make it wide enough.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100

// 3.6 do-while 循环
// itoa 函数是 atoi 函数的逆函数，将数字转换为字符串

void itoav2(int n, char s[], int width);
void reverse(char s[]);

int main()
{
  int n = 324;
  char s[MAXLEN];

  itoav2(n, s, 6);
  printf("%s\n", s);

  return 0;
}

/* itoa: convert n to a string s padded if necessary */
void itoav2(int n, char s[], int width)
{
  int i, sign;

  sign = n;
  n = abs(n); // sets n to be positive
  i = 0;
  do
  { // generate digits in reverse order
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
  {
    s[i++] = '-';
  }

  // 添加一个参数
  // 设置 padding

  // 注意，此处 for 语句不写初始化段
  for (; i < width; i++) // add padding
  {
    s[i] = ' ';
  }

  s[i + 1] = '\0';
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
