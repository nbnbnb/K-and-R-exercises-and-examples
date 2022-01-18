/*In a two's complement number rerpresentation, our version of itoa does not 
  handle the largest negative number, that is the value fo n equal to (-2 to 
  the power wordsize-1). Modify it to print that value correctly, regardless of
  the machine on which it runs.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 3.6 do-while 循环
// itoa 函数是 atoi 函数的逆函数，将数字转换为字符串
#define MAXLEN 100

// 将 int 转换为字符数组
void itoa(int n, char s[]);

// 反转字符数组
// 例如：将 '423' 转成 '324'
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

  sign = n;
  // abs 是 <stdlib.h> 中的函数
  n = abs(n); // sets n to be positive
  i = 0;

  // generate digits in reverse order
  do
  {
    // 技巧
    // 数字 + 字符 0 就是 "ASCII 数字"
    // '0' = 48
    // 4 + '0' = 52 = '4'

    // 其实都是同一个意思
    // ASCII '0'~'9' 是顺序排序的，每个间隔都是 1，从 '0' 开始
    // 所以 '0' + i 就是向下移动 i 个顺序

    s[i++] = n % 10 + '0';

    // 先执行 do 里面的语句

    // 每次取余都是反过来的
    // 最后 324 得到 '423'

    // 4 -> n = 32
    // 3 -> n = 3
    // 2 -> n = 0

  } while ((n /= 10) > 0);

  // 如果小于 0
  // 加上 - 符号
  if (sign < 0)
  {
    s[i++] = '-';
  }

  // 结尾 EOF
  s[i] = '\0';

  // 将 '423' 转成 '324'
  // 将 '423-' 转成 '-324'
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
