/* Write a program to print a histogram of the lengths of words in its input.
   It is easy to draw the histogram with the bars horizontal; a vertical
   orientation is more challenging. */

// 1.6 数组 打印输入字符的直方图信息（难点：绘制字符）
#include <stdio.h>

// 最大支持统计 20 个字符内的单词
#define MAXLEN 20

int main(void)
{
  int c, i, j;
  int a[MAXLEN];

  for (i = 0; i <= MAXLEN; ++i)
  {
    // 初始化数组
    // 数组用于统计相同字符单词的个数
    a[i] = 0;
  }

  i = 0;

  while ((c = getchar()) != EOF)
  {
    if ((c == ' ') || (c == '\n') || (c == '\t'))
    {

      // 遇到了空格
      // 将其索引对应的计数 + 1（索引数就是单词的长度）
      ++a[i];

      // 重置单词个数
      i = 0;
    }
    else
    {
      // 如果不是空格
      // 则单词个数 + 1
      // 注意：最大不能超过 20
      ++i;
    }
  }

  printf("Horizontal Histogram:\n\n");

  // 下面就是画图

  // 注意：printf 如果不带 \n，那么就不会换行
  // 所以，下面可以在一行中打印各种样式

  // 注意：是从第一个索引开始打印（对应一个字符的单词数量）
  for (i = MAXLEN; i >= 1; --i)
  {

    printf("%2d let w |", i);

    // 一个计数就输出一个 *
    for (j = 0; j < a[i]; ++j)
    {
      printf("*");
    }

    printf("\n");
  }

  printf("         |");

  for (i = 7; i <= 60; ++i)
  {
    printf("_");
  }

  printf("\n          Number of words\n");

  return 0;
}

/**

输入 12 4 66 986 gdkgjdkg jg32fds 345d 04 44ferf

输出

20 let w |
19 let w |
18 let w |
17 let w |
16 let w |
15 let w |
14 let w |
13 let w |
12 let w |
11 let w |
10 let w |
 9 let w |
 8 let w |*
 7 let w |*
 6 let w |*
 5 let w |
 4 let w |*
 3 let w |*
 2 let w |***
 1 let w |*
         |______________________________________________________
          Number of words

 */