/* Reads a set of text lines and prints the longest one. */
// 1.9 数组
#include <stdio.h>

#define MAXLINE 1000

// 自定义函数
// 读取输入的下一行
int getline(char line[], int maxline);

void copy(char to[], char from[]);

int main(void)
{
  int len; // current line length
  int max; // maximum lenght seen so far

  // 字符数组
  // 下面初始化时就分配了内存

  // 新读入的行
  char line[MAXLINE]; // current input line

  // 最长的行
  char longest[MAXLINE]; // longest line saved here

  // 记录最长行的字符数
  max = 0;

  // getline 函数返回后
  // 再次读取新行
  // 直到读取新行的字符为 0
  while ((len = getline(line, MAXLINE)) > 0)
  {
    // 如果当前行字符数大于已经记录的最长行
    // 则将其保存在 longest 数组中
    if (len > max)
    {
      max = len;

      // 将 line 中的字符拷贝到 longest 中
      copy(longest, line);
    }
  }

  if (max > 0) // there was a line
  {
    printf("%s", longest);
  }

  return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  // 将输入的内容拷贝到 s 字符数组中
  // i 先初始化为 0
  // ++i 表示字符计数
  for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    // 行数累加
    ++i;
  }

  // 给字符数组结尾设置为 EOF
  s[i] = '\0';

  // 返回字符数（不包括 EOF）
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{

  int i;

  i = 0;

  // 拷贝
  // 遇到 EOF 则终止
  while ((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}
