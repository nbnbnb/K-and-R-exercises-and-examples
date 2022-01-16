#include <stdio.h>

#define MAXLEN 100

// 3.5 while 循环与 for 循环

// 首先输入一个数字，表示数组有几个元素
// 输入 10
// 然后输入 10 个数字，每输入一个，回车
// 例如输入 6 7 0 9 8 3 2 4 1 5
// 最后输出 0 1 2 3 4 5 6 7 8 9 

void shellsort(int v[], int n);

int main(void)
{
  int v[MAXLEN], n, i;

  printf("Enter the number of elements: ");

  // 输入几个数字
  // 注意，scanf 的写法
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    // 把输入的数字，存入 v 数组中
    // 注意，scanf 的写法
    scanf("%d", &v[i]);
  }

  // 对输入的数组进行排序
  shellsort(v, n);

  for (i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }

  printf("\n");
  return 0;
}

// 使用间隔跳跃排序法
/* shellsort: sort v[0]...v[n-1] into increasing order. */
void shellsort(int v[], int n)
{
  int i, j, gap, temp;

  // 假如 n = 10
  // 则 gap = 5 2 1 执行循环
  for (gap = n / 2; gap > 0; gap /= 2)
  {
    // 当 gap = 5 的时候
    // i 就是 5 6 7 8 9

    for (i = gap; i < n; i++)
    {
      // *** gap = 5 ***
      // i   = 5
      // j   = 0
      // swap(0,5)
      // j -= gap = -5 => break

      // i   = 6
      // j   = 1
      // swap(1,6)
      // j -= gap = -4 => break

      // i   = 7
      // j   = 2
      // swap(2,7)
      // j -= gap = -3 => break

      // i   = 8
      // j   = 3
      // swap(3,8)
      // j -= gap = -2 => break

      // i   = 9
      // j   = 4
      // swap(4,9)
      // j -= gap = -1 => break

      // *** gap = 2 ***

      // i   = 2
      // j   = 0
      // swap(0,2)
      // j -= gap = -2 => break

      // i   = 3
      // j   = 1
      // swap(1,3)
      // j -= gap = -1 => break

      // i   = 4
      // j   = 2
      // swap(2,4)
      // j -= gap = 0
      // v[0] > v[2] break -> 已经比对过

      // i   = 5
      // j   = 3
      // swap(3,5)
      // j -= gap = 1
      // v[1] > v[3] break -> 已经比对过

      // i   = 6
      // j   = 4
      // swap(4,6)
      // j -= gap = 2
      // v[2] > v[4] break -> 已经比对过

      // i   = 7
      // j   = 5
      // swap(5,7)
      // j -= gap = 3
      // v[3] > v[5] break -> 已经比对过

      // i   = 8
      // j   = 6
      // swap(6,8)
      // j -= gap = 4
      // v[4] > v[6] break -> 已经比对过

      // i   = 9
      // j   = 7
      // swap(7,9)
      // j -= gap = 5
      // v[5] > v[7] break -> 已经比对过

      // *** gap = 1 ***
      // i   = 1
      // j   = 0
      // swap(0,1)
      // j -= gap = -1 break

      // i   = 2
      // j   = 1
      // swap(1,2)
      // j -= gap = 0
      // v[0] > v[1] break -> 已经比对过

      // i   = 3
      // j   = 2
      // swap(2,3)
      // j -= gap = 1
      // v[1] > v[2] break -> 已经比对过

      // i   = 4
      // j   = 3
      // swap(3,4)
      // j -= gap = 2
      // v[2] > v[3] break -> 已经比对过

      // i   = 5
      // j   = 4
      // swap(4,5)
      // j -= gap = 3
      // v[3] > v[4] break -> 已经比对过

      // i   = 6
      // j   = 5
      // swap(5,6)
      // j -= gap = 4
      // v[4] > v[5] break -> 已经比对过

      // i   = 7
      // j   = 6
      // swap(6,7)
      // j -= gap = 5
      // v[5] > v[6] break -> 已经比对过

      // i   = 8
      // j   = 7
      // swap(7,8)
      // j -= gap = 6
      // v[6] > v[7] break -> 已经比对过

      // i   = 9
      // j   = 8
      // swap(8,9)
      // j -= gap = 7
      // v[7] > v[8] break -> 已经比对过

      for (j = i - gap; (j >= 0 && v[j] > v[j + gap]); j -= gap)
      {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
  }
}
