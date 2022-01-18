/* Write a function strrindex(s,t), which returns the position of the rightmost 
   occurence of t in s, or -1 if there is none.*/
#include <stdio.h>
#include <string.h>

// 4.1 函数的基本知识
// 输入：abcxyz
// 返回：3
// 字符 x 在 abcxyz 中的索引

#define MAXLINE 1000 // maximum input line length

int getline(char line[], int max);
int strindex(char source[], char char_to_find);

char ch = 'x'; // pattern to search

/* find all lines matching pattern */
int main(void)
{
  char line[MAXLINE];

  while (getline(line, MAXLINE) > 0)
  {
    printf("%d\n", strindex(line, ch));
  }

  return 0;
}

// 通用函数：读取输入行
/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }

  // 如果有换行符
  // 则也添加到末尾
  if (c == '\n')
  {
    s[i++] = c;
  }

  // 设置结尾符
  s[i] = '\0';

  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char c)
{
  int i;

  // 判断条件：s[i] != c
  // 如果相等，则跳出 for 循环
  for (i = strlen(s) - 1; (s[i] != c) && (i >= 0); i--)
    ;

  return i ? i : -1;
}
