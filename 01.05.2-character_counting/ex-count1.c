/* count characters in input; 1st version */
// 1.5.2 字符计数
#include <stdio.h>

int main(void)
{

  long nc;

  // 一定要赋初始值，要不 nc 就可能为任意值
  nc = 0;

  while (getchar() != EOF)
  {
    // 也可以用 nc = nc +1
    // 但是 ++nc 更精炼一些，效率也更高
    ++nc;
  }

  // 测试

  // 输入 123456 后，输入回车
  // 然后 Ctrl+C 输入 EOF
  // 最终会返回 7

  // 为什么是 7？
  // 因为回车也是一个字符

  // 注意：一定要输入回车，回车将输入流发送给 getchar 函数

  printf("%ld\n", nc);

  return 0;
}
