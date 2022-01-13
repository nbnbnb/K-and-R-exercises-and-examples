/* Write a program detab that replaces tabs in the input with the proper number
   of blanks to space to the next tab stop. Assume a fixed set of ab stops, say 
   every n columns. */
// 1.10 外部变量与作用域
// 练习：1-20 编写程序 detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方
#include <stdio.h>

#define TABLEN 5
#define MAXLINE 1000

void print_detab(char line[]);
int getline(char line[], int maxline);

int main(void)
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
  {
    print_detab(line);
  }

  return 0;
}

int getline(char l[], int lim)
{
  int c, i;

  for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
  {
    l[i] = c;
  }

  if (c == '\n')
  {
    l[i] = c;
    ++i;
  }

  l[i] = '\0';
  return i;
}

void print_detab(char s[])
{
  int i, j, n;

  // 如果第一个字符就是换行符
  if (s[0] == '\t')
  {
    // 则输出 5 个空格
    for (i = 0; i < TABLEN; ++i)
    {
      putchar(' '); // if the first char is tab print TABLEN spaces
    }
  }

  for (i = 0; (s[i] != '\0'); ++i)
  {
    if (s[i] != '\t')
    {
      // 不是换行符，则输出
      putchar(s[i]); // print char if is not tab
    }
    // 如果在行中遇到了换行符，并且当前的字符索引 % 5 取模不是 0
    else if (n = (i % TABLEN)) // replace tab with appropriate no. of chars.
    {

      // 12345678        aaa
      // i = 8，n = 3，输出 2 个 *
      // 12345678**aaa

      // 123456789       aaa
      // i = 9，n = 4，输出 1 个 *
      // 123456789*aaa

      // 那么输出（5 - 取模）个空格
      for (j = 1; j <= (TABLEN - n); ++j)
      {
        putchar('*');
      }
    }
    // 刚好 5 个字符遇到一个 Tab，输出一个空格
    else
    {
      putchar(' ');
    }
  }
}
