/* count lines, words, and characters in input */
// 1.5.4 单词计数
#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

int main(void)
{
  int c, nl, nw, nc, state;

  // 下面这段程序是 UNIX 系统中 wc 程序的骨干部分

  state = OUT;
  nl = nw = nc = 0;

  while ((c = getchar()) != EOF)
  {
    // 字符总数
    ++nc;

    if (c == '\n')
    {
      // 行总数
      ++nl;
    }

    // 单词结束
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
    }
    // 单词开始
    else if (state == OUT)
    {
      state = IN;
      // 单词总数
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
