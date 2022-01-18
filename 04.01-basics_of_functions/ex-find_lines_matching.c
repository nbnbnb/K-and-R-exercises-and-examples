#include <stdio.h>

#define MAXLINE 1000 // maximum input line length

// 4.1 函数的基本知识

// 输入：hahahclouldabc
// 返回：find match index 7
int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // pattern to search

/* find all lines matching pattern */
int main(void)
{
  char line[MAXLINE];

  while (getline(line, MAXLINE) > 0)
  {
    int matchIndex = strindex(line, pattern);
    if (matchIndex >= 0)
    {
      printf("%s", line);
      printf("find match index %d", matchIndex);
    }
  }

  return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    s[i++] = c;
  }

  if (c == '\n')
  {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++)
  {
    // 将源字符与目标字符的每一位进行比较
    // 如果它们相等，则继续一个字符比较
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;

    //  t[k] == '\0' 表示源字符与目标字符全部匹配
    if (k > 0 && t[k] == '\0')
    {
      // 返回是在第几个字符匹配的
      return i;
    }
  }

  // 如果没有找到，返回 -1
  return -1;
}
