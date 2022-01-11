/* count characters in input; 2nd version */
#include <stdio.h>

int main(void)
{
  // long 至少要占用 32 位
  // 在某些机器上 long 与 int 长度相同
  // 有些机器上 int 可能只有 16 位长度

  // 此处，使用 double 类型可以处理更大的数字（64 为2）
  double nc;

  // while 语句与 for 语句的有点之一就是在执行循环体之前就对条件测试
  // 如果条件不满足，则不执行循环体

  // for 替代 while 循环的一种写法
  // 注意：设置一个空语句
  for (nc = 0; getchar() != EOF; ++nc)
    ;

  // %.0f 不打印小数点和小数部分
  printf("%.0f\n", nc);

  return 0;
}
