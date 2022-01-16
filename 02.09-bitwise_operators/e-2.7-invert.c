/* Write a function invert(x,p,n) that returns x with the n bits that begin at position
   p inverted (i.e. 1 changed into 0 and vice versa, leaving the others unchanged. */
#include <stdio.h>

// 2.9 按位运算符

int invert(int x, int p, int n);

int main(void)
{
  int x, p, n;

  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter position p: ");
  scanf("%d", &p);

  printf("Enter number of bits n: ");
  scanf("%d", &n);

  printf("The processed number is: %d\n", invert(x, p, n));

  return 0;
}

int invert(int x, int p, int n)
{

  // x = 5
  // p = 2
  // n = 3

  int ref = 0;

  // 0   = 0000 0000 0000 0000
  // ~0  = 1111 1111 1111 1111 = -1

  // 计算 1111 1111 1111 1111 表示的 10 进制值
  // 由于第一位是 1，所以是负数
  // 按照负数的规则（取反 + 1）
  // 取反得到 0000 0000 0000 0000
  // +1  得到 0000 0000 0000 0001
  // 最后十进制得到 1
  // 由于是负数，乘以 -1 得到 -1

  // 反过来，计算 -1 的二进制
  // 首先，正数 1 的二进制值是 0000 0000 0000 0001
  // 然后减去 1，得到 0000 0000 0000 0000
  // 最后，取反，得到 1111 1111 1111 1111

  // ~0 = 1111 1111 1111 1111 << 3 = 1111 1111 1111 1000 = -8
  // ref = -8
  ref = ~ref << n;

  // ~ref = 0000 0000 0000 0111
  // ~ref << 2 = 0000 0000 0001 1100 = 28
  // ref = 0000 0000 0001 1100 = 28
  ref = ~ref << p; // mark the exact bits that need negation

  // ref  = 0000 0000 0001 1100
  // ~ref = 1111 1111 1110 0011
  // (~ref & x) = 1111 1111 1110 0011 & 0000 0000 0000 0101 = 0000 0000 0000 0001 = 1
  // (ref & ~x) = 0000 0000 0001 1100 & 1111 1111 1111 1010 = 0000 0000 0001 1000 = 24
  // 0000 0000 0000 0001 | 0000 0000 0001 1000 = 0000 0000 0001 1001 = 25
  // 最后结果 25
  return ((~ref & x) | (ref & ~x));
}
