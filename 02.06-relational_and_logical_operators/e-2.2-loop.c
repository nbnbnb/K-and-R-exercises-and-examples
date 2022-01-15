/* Write a loop equivalent to the for loop above without using && or ||. */

// 2.6 关系运算符与逻辑运算符

// 在不使用运算符 && 或 || 的条件下，编写一个与 for 循环等价的语句

#include <stdio.h>

int main(void)
{
  int i = 0, lim = 10, c;
  char s[10];

  while ((c = getchar()) != EOF)
  {
    if (c != '\n')
    {
      // 只能输入 10 个字符
      if (i <= lim - 1)
      {
        s[i] = c;
        ++i;
      }
    }
  }

  // 设置 EOF
  // 避免输出乱码
  s[10] = '\0';

  printf("%s\n", s);
  return 0;
}
