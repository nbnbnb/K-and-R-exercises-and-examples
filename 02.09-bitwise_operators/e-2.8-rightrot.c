/* Write a function rightrot(x,n) that returns the value of the integer x rotated
   to the right by n bit positions. */
#include <stdio.h>

// 2.9 按位运算符

int rightrot(int x, int n);

int main(void)
{
  int x, n;

  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter number of bits n: ");
  scanf("%d", &n);

  printf("The processed number is: %d\n", rightrot(x, n));

  return 0;
}

int rightrot(int x, int n)
{

  // x = 5
  // n = 3

  int end = 0;

  // ~0 = 1111 1111 1111 1111 = -1
  // 1111 1111 1111 1111 << 3 = 1111 1111 1111 1000
  // ~(1111 1111 1111 1000) = 0000 0000 0000 0111 = 7
  // end = 7
  end = ~(~end << n);

  // 0000 0000 0000 0101 & 0000 0000 0000 0111 = 0000 0000 0000 0101 = 5
  // end = 5
  end = x & end;

  // sizeof(int) = 4
  // 0000 0000 0000 0000 0000 0000 0000 0101 << 29
  // 1010 0000 0000 0000 0000 0000 0000 0000 = -1610612736
  // end = -1610612736
  end = end << (8 * sizeof(x) - n);

  // 5 >> 3 = 0000 0000 0000 0000 0000 0000 0000 0101 >> 3 = 0000 0000 0000 0000 0000 0000 0000 = 0
  // 0000 0000 0000 0000 0000 0010 1000 | 1010 0000 0000 0000 0000 0000 0000 0000 = 0000 0000 0000 0000 0000 0000 0000 = -1610612736
  return ((x >> n) | end);
}
