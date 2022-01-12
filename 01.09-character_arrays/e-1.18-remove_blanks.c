/* Write a program to remove trailing blanks and tabs from each line
   of input, and to delete entirely blank lines. */
// 1.9 字符数组
// 练习 1-18：编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行
#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int limit);
void print_line(char line[], int line_length);
int is_blank(char line[]);

int main(void)
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
  {
    print_line(line, len);
  }

  return 0;
}

// 通用函数
// 构造字符数组，并返回数组长度
int getline(char s[], int lim)
{
  int c, i;

  for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  // 注意：返回的长度不包括 EOF
  s[i] = '\0';

  return i;
}

/* print_line: prints a formated line - no trailing blanks, tabs or empty lines */
void print_line(char l[], int len)
{
  int i, j;

  // 判断全是空格
  if (is_blank(l)) // exit if blank line
  {
    return;
  }
  // 注意，索引从 len - 2 开始
  // 表示从倒数第二个字符开始判断（因为 getline 中设置的倒数第一个字符是 EOF）
  // 如果倒数第二个字符是 ' '，则将其截断为 EOF
  for (i = len - 2; (l[i] == ' ') && (i >= 0); --i) // remove all trailing blanks
  {
    l[i] = '\0';
  }

  // 满足 --i 条件
  // 上面替换过空格
  if (i < len - 2) // if there were blanks add \n to the string
  {
    l[i + 1] = '\n';
  }

  for (j = 0; l[j] != '\0'; ++j) // print all character that are not tabs
  {
    // 不打印换行符
    if (l[j] != '\t')
    {
      putchar(l[j]);
    }
  }
}

/* returns 1 if line is blank and 0 otherwise */
int is_blank(char l[])
{
  int i;

  // 单换行符
  if (l[0] == '\n')
  {
    return 1;
  }

  for (i = 0; l[i] != '\n'; ++i)
  {
    // 只要有任意一个字符不是空格，则返回
    if ((l[i] != ' ') && (l[i] != '\t'))
    {
      return 0;
    }
  }

  return 1;
}
