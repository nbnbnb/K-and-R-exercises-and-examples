/* count lines in input */
// 1.5.3 行计数
#include <stdio.h>

int main(void)
{

  int c, nl;

  nl = 0;

  while ((c = getchar()) != EOF)
  {
    // 单引号的字符表示一个 “整型值”
    // 是小的整型数的另一种写法
    if (c == '\n')
    {
      ++nl;
    }
  }

  printf("%d\n", nl);

  return 0;
}
