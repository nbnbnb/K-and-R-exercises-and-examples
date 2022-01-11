/* Write a program to print a histogram of the frequencies of different 
   characters in its input. */
// 1.6 数组 统计字符信息的直方图
#include <stdio.h>

#define ALL_CHARS 26
#define ALL_NUMS 10

int main(void)
{
  int c, i, j;
  int ch[ALL_CHARS], num[ALL_NUMS];

  for (i = 0; i < ALL_CHARS; ++i)
  {
    ch[i] = 0;
  }

  for (i = 0; i < ALL_NUMS; ++i)
  {
    num[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    if (c >= '0')
    {
      if (c <= '9')
      {
        // [0~9]
        ++num[c - '0'];
      }
      else if (c >= 'A')
      {
        if (c <= 'Z')
        {
          // [A-Z]
          ++ch[c - 'A'];
        }
        else if (c >= 'a')
        {
          if (c <= 'z')
          {
            // [a~z]
            ++ch[c - 'a'];
          }
        }
      }
    }
    // 注意：大小写字符都统计在一起
    // 其它字符都忽略
  }

  printf("Horizontal Histogram:\n\n");

  // 打印字符的统计信息
  for (i = ALL_CHARS - 1; i >= 0; --i)
  {
    printf("%c |", ('a' + i));

    for (j = 0; j < ch[i]; ++j)
    {
      printf("*");
    }

    printf("\n");
  }

  // 打印数字的统计信息
  for (i = ALL_NUMS - 1; i >= 0; --i)
  {
    printf("%c |", ('0' + i));

    for (j = 0; j < num[i]; ++j)
    {
      printf("*");
    }

    printf("\n");
  }

  printf("  |");

  for (i = 7; i <= 60; ++i)
  {
    printf("_");
  }

  printf("\n   Frequency\n");

  return 0;
}

/**

输入 sdfdklsfjklfj34908efjHJHDKHKDHJSgfg2=-540-tigkgkgdfgfdfg

输出

Horizontal Histogram:

z |
y |
x |
w |
v |
u |
t |*
s |***
r |
q |
p |
o |
n |
m |
l |**
k |******
j |*****
i |*
h |****
g |*******
f |********
e |*
d |******
c |
b |
a |
9 |*
8 |*
7 |
6 |
5 |*
4 |**
3 |*
2 |*
1 |
0 |**
  |______________________________________________________
   Frequency


 */