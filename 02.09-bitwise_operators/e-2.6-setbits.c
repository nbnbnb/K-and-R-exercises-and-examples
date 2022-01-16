/* Write a function setbits(s,p,n,y) that returns x with the n bits that begin at
   position p set to the rightmost n bits of y, leaving the other bits unchanged. */
#include <stdio.h>

// 2.9 按位运算符

int setbits(int x, int p, int n, int y);

int main(void)
{
  int x, p, n, y;

  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter y: ");
  scanf("%d", &y);

  printf("Enter position p: ");
  scanf("%d", &p);

  printf("Enter number of bits n: ");
  scanf("%d", &n);

  printf("The processed number is: %d\n", setbits(x, p, n, y));

  return 0;
}

int setbits(int x, int p, int n, int y)
{
  // x = 5
  // y = 8
  // p = 2
  // n = 3

  // 8 = 1000 >> (2-1) = 0100 = 4
  // y = 4
  y = y >> (p - 1); // move the bits starting at pos p to the end

  // ~0 = 1111 1111 1111 1111 = -1

  // (-1 << 3) == 1111 1111 1111 1000 == -8
  // ~(-8) = 0000 0000 000 0111 = 7
  // 000 0000 000 0100 & 0000 0000 000 0111 = 0000 0000 000 0100 = 4
  // y = 4
  y = y & ~(~0 << n); // null all the bits from a pos higher than n

  // (~0 << 3) == 1111 1111 1111 1000 == -8
  // 0000 0000 0000 0101 & 1111 1111 1111 1000 = 0000 0000 0000 0000 = 0
  // x = 0
  x = x & (~0 << n); // null the last n bits

  // 0000 | 0100 = 0100 = 4
  return (x | y);
}
