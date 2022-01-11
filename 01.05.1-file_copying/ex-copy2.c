/* copy input to output; 2nd version */
// 1.5.1 文件复制
#include <stdio.h>

int main(void)
{
  int c;

  // 重构到一行语句中

  // 注意：通过括号来控制操作符优先级
  while ((c = getchar()) != EOF)
  {
    putchar(c);
  }

  return 0;
}
