/* copy input to output; 1st version */
// 1.5.1 文件复制
#include <stdio.h>

int main(void)
{
  int c;

  // 注意：在控制台输入 Ctrl+C，表示的就是 EOF

  // 从控制台输入一些字符，然后回车
  // 注意，可以输入连续多个字符，在循环中，getchar() 都会将其读出
  c = getchar();
  while (c != EOF)
  {
    // 然后将字符再输出到控制台
    putchar(c);
    // 循环输入
    c = getchar();
  }

  return 0;
}
