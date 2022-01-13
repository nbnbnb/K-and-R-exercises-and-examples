/* Write a program entab that replaces strings of blanks by the minimum number of tabs
   and blanks to achieve the same spacing. Use the same tab stops as for detab. */
// 1.10 外部变量与作用域
// 练习：1-21 编写程序 entab，将空格串替换为最少数量的制表符和空格，但要保持单词间的间隔不变
#include <stdio.h>

// 一个 Tab 占用 3 个空格
#define TABLEN 3
#define MAXLINE 1000

int getline(char line[], int limit);
void print_detab(char line[]);
int tabs_to_insert_in(char lint[], int position);

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
  int i;
  char c;

  for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && c != '\n'; ++i)
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

/* print_detab: prints the string line with tabs instead of blanks */
void print_detab(char s[])
{
  int i, j, tabs;

  i = 0;

  while (s[i] != '\0')
  {
    // 如果遇到了空格
    // 计算需要 Tab 的个数
    if ((s[i] == ' ') && (tabs = tabs_to_insert_in(s, i))) // if char is space
    {
      // 如果需要 Tab
      for (j = 1; j <= tabs; ++j) // and can insert tabs in string instead of spaces
      {
        // 输出 Tab，表示 3 个字符
        // Tab 输出字符对不齐，用 * 代替
        putchar('*');
        putchar('*');
        putchar('*');
        // 每次跳 3 个
        i += TABLEN; // jump pass the spaces transformed in tabs
      }
    }
    // 如果不需要 Tab，则正常打印字符或者空格
    else
    {
      putchar(s[i]);
      ++i;
    }
  }
}

// 返回应该使用几个 Tab
/* tabs_to_insert: returns the number of tabs that can replace spaces */
int tabs_to_insert_in(char s[], int n)
{
  int i, j;

  j = 0;
  // 注意，此处是从传入的 n 开始的
  for (i = n; (s[i] != '\n') && (s[i] == ' '); ++i)
  {
    // 计算空格个数
    ++j;
  }

  // 如果空格个数大于等于 3
  if (j >= TABLEN)
  {
    // 则应该使用 Tab
    // 取余
    return (j / TABLEN);
  }
  else
  {
    // 小于 3 个，则不能使用 Tab
    return 0;
  }
}
