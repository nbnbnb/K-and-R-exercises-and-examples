/* Write a program to count blanks, tabs and newlines */
// 1.5.3 统计 空格/Tab/新行
#include <stdio.h>

int main(void)
{
  int blanks, tabs, newlines, ch;

  blanks = 0;
  tabs = 0;
  newlines = 0;

  while ((ch = getchar()) != EOF)
  {
    if (ch == ' ')
    {
      // 空格计数
      ++blanks;
    }
    else if (ch == '\n')
    {
      // 新行计数
      ++newlines;
    }
    else if (ch == '\t')
    {
      // Tab 计数
      ++tabs;
    }
  }

  printf("Blanks: %d\nLines: %d\nTabs: %d\n", blanks, newlines, tabs);

  return 0;
}
