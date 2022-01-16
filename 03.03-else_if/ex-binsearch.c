#include <stdio.h>

// 3.3 else-if 语句

// 练习 二分搜索的右一种写法

int binsearch(int x, int v[], int n);

int main(void)
{
  // 已经排序的数组
  int v[] = {1, 3, 4, 11, 33, 130, 132, 153, 166}; // sorted array

  printf("%d\n", binsearch(11, v, 9));

  return 0;
}

int binsearch(int x, int v[], int n)
{

  // x 表示要查找的数值
  // n 表示数组的长度

  int low, high, mid;

  low = 0;
  // 最高位索引是数组长度 - 1
  high = n - 1;

  while (low <= high)
  {
    // 中位索引
    mid = (low + high) / 2;

    if (x < v[mid])
    {
      // 要查询的值在左边
      // 修正最大索引为中间索引 - 1
      high = mid - 1;
    }
    else if (x > v[mid])
    {
      // 要查询的值在右边
      // 修正最小索引为中间索引 + 1
      low = mid + 1;
    }
    else // found match
    {
      // 不是 > <
      // 那么就是 =
      // 找打了
      return mid;
    }
  }

  // 没有找到，返回 -1
  return -1;
}
