/* Our binary search makes two tests inside the loop, when ont would suffice 
   (at the price of more tests outside). Write a version with only one test
   inside the loop. */
#include <stdio.h>

// 3.3 else-if 语句

int binsearch(int x, int v[], int n);

int main(void)
{
  // 已经排序的数组
  int v[] = {1, 3, 4, 11, 33, 130, 132, 153, 166}; // sorted array

  printf("%d\n", binsearch(130, v, 9));

  return 0;
}

// 二分搜索
// x 表示要搜索的值
// n 表示数组的长度
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  // 表示前后的两个索引
  low = 0;
  // 最后的一个索引值是数组长度 - 1
  high = n - 1;

  while ((low <= high) && (v[mid] != x))
  {
    // 计算中位数
    mid = (low + high) / 2;

    // 这里不用判断 ==
    // 因为 while 循环里面已经判断了
    if (x < v[mid])
    {
      // 要查询的值在左边
      // 修正最大索引为中间索引 - 1
      high = mid - 1;
    }
    else
    {
      // 要查询的值在右边
      // 修正最小索引为中间索引 + 1
      low = mid + 1;
    }
  }

  // 找不到，则返回 -1
  return ((v[mid] == x) ? mid : -1);
}
