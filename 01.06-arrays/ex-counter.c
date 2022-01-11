/* count digits, white spaces, ohers*/
// 1.6 数组
#include <stdio.h>

int main(void)
{

  int c, i, nwhite, nother;

  // 使用一个数组存放各个数字出现的次数
  int ndigit[10];

  nwhite = nother = 0;

  for (i = 0; i <= 9; i++)
  {
    // 数组中每个元素都初始化为 0
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    // 数字类型
    if (c >= '0' && c <= '9')
    {
      // 这里取了一个巧
      // [c - '0'] 刚好得到一个 [0~9] 的数字映射到数组索引上
      ++ndigit[c - '0'];
    }
    // 空格类型
    else if ((c == ' ') || (c == '\t') || (c == '\n'))
    {
      ++nwhite;
    }
    // 其它类型
    else
    {
      ++nother;
    }
  }

  printf("digits =");

  for (i = 0; i <= 9; ++i)
  {
    // 打印 0~9 出现的次数
    printf(" %d", ndigit[i]);
  }

  printf(", white space = %d, other = %d\n", nwhite, nother);

  return 0;
}
