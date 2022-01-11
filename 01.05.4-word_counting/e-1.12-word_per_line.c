/* Write a program that prints its input one word per line. */
// 1.5.4 把输入的每个单词每一行输出
#include <stdio.h>

int main(void)
{
  int c;

  while ((c = getchar()) != EOF)
  {
    // 设置换行符
    if ((c == ' ') || (c == '\n') || (c == '\t'))
    {
      printf("\n");
    }
    else
    {
      putchar(c);
    }
  }

  return 0;
}
