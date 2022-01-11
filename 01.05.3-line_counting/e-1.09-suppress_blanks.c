/* Write a program to copy its input to its output, replacing each string
   of one or more blanks by a single blank. */
// 1.5.3 将多个空格替换为单个空格，然后输出
#include <stdio.h>

int main(void)
{
  int ch, prev;

  prev = 1;

  while ((ch = getchar()) != EOF)
  {
    // 当前是空格
    if (ch == ' ')
    {
      // 前一个不是空格
      if (prev != ' ')
      {
        // 输出空格
        putchar(ch);
      }

      // 设置前一个字符（空格）
      prev = ch;
    }
    else
    {
      // 输出字符
      putchar(ch);
      // 设置前一个字符（非空格）
      prev = ch;
    }
  }

  return 0;
}
