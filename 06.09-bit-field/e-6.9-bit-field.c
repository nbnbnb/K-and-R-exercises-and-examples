#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 6.9 位字段

// “字”（word）是单个的存储单元，它与具体的实现有关

// 这里定义了一个变量 flags，它包含 3 个一位字段
// 冒号后面的数字表示字段的宽度（用二进制位表示）
// 字段声明为 unsigned int 类型，以保证它们是无符号量
struct
{
  unsigned int is_keyword : 1;
  unsigned int is_extern : 1;
  unsigned int is_static : 1;
} flags;

int main(void)
{

  return 0;
}
