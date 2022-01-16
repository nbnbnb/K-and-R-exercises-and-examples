#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

// 3.5 while 循环与 for 循环

// 将输入的字符串，转换为 10 进制
// 例如：
// 输入 1234sss
// 输出 1234

int a_toi(char s[]);

int main(void)
{
  char s[MAXLEN], c;
  int i = 0;

  printf("Enter the string: ");

  while ((c = getchar()) != EOF)
  {
    s[i++] = c;
  }

  s[i] = '\n';

  printf("%d\n", a_toi(s));

  return 0;
}

int a_toi(char s[])
{
  int i, n, sign;

  // isspace 是 ctype.h 中的声明
  // 去掉前面的空格
  for (i = 0; isspace(s[i]); i++)
    ;

  // 判断符号
  sign = (s[i] == '-') ? -1 : 1;

  // 跳过符号
  // 索引 + 1
  if ((s[i] == '-') || (s[i] == '+')) // skip sign
  {
    i++;
  }

  // isdigit 是 ctype.h 中的声明
  // 如果是数字
  for (n = 0; isdigit(s[i]); i++)
  {
    // 技巧： s[i] - '0' 转换为数字
    // 10 * n 递增计算
    n = 10 * n + (s[i] - '0');
  }

  return sign * n;
}
