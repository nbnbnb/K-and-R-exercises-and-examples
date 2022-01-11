/* copy input to output; 1st version */
// 1.5.1 文件复制
#include <stdio.h>

int main(void)
{
  // 这里之所以不把 c 声明成 char 类型
  // 是因为它必须足够大
  // 除了能存储任何可能的字符外海要能存储文件结束符 EOF = -1
  int c;

  // 注意：在控制台输入 Ctrl+Z，表示的就是 EOF

  // 从控制台输入一些字符，然后回车
  // 注意，可以输入连续多个字符，在循环中，getchar() 都会将其读出
  c = getchar();
  // C 语言中的 bool 是 1 和 0
  // 所以，表达式 c != EOF 返回的就是 1 或 0
  while (c != EOF)
  {
    // 然后将字符再输出到控制台
    putchar(c);
    // 循环输入
    c = getchar();
  }

  return 0;
}
