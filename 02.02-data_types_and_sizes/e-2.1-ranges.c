/* Write a program to determine the ranges of char, short, int, and long variables,
   both signed and unsigned, by printing the appripriate values from standard
   headers and by direct computation. */

// 2.2 数据类型及长度

// 各编译器可以根据硬件特性自主选择合适的类型长度

// 但需要遵循的限制

// short 与 int 类型至少为 16 位
// long 类型至少位 32 位

// short 类型不得长于 int 类型
// int 类型不得长于 long 类型

// 每个实现的定义，在标准头文件中
// <limits.h> 和 <float.h>

#include <stdio.h>

int compute_char(void);

int main(void)
{

  // x64 机器

  // 1
  printf("char: %d\n", sizeof(char));

  // 2
  printf("short: %d\n", sizeof(short));

  // int 通常代表 “特定机器” 中整数的 “自然长度”
  // int 类型可以为 16 位或者 32 位
  // 4
  printf("int: %d\n", sizeof(int));

  // 4
  printf("unsigned int: %d\n", sizeof(unsigned int));

  // 4
  printf("signed int: %d\n", sizeof(signed int));

  //4
  printf("long: %d\n", sizeof(long));

  // 4
  printf("\nfloat: %d\n", sizeof(float));

  // 8
  printf("double: %d\n", sizeof(double));

  // 16
  printf("long double: %d\n", sizeof(long double));

  // 1
  printf("\nComputed range of char: %d\n", compute_char());

  // the range for other types can be computed like this as well
  return 0;
}

/* compute_char: returns the range of a char in bytes. */
int compute_char(void)
{
  char x = 1;
  int i = 0;

  while (x)
  {
    // 把字符指针向左移动 1 位（增大）
    // 移动 8 次后（Java/.NET 需要移动 16 次，它们占用两个字节）
    // x == 0
    // 表示一个字符占用了 8 位
    x = x << 1; // shift left by 1 bit
    // printf("%d", i);
    ++i;
  }

  // 将位转换位字节
  return (i / 8); // transform bits in bytes
}
