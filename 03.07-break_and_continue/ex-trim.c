#include <stdio.h>
#include <string.h>

// 3.7 break 语句与 continue 语句

#define MAXLEN 100

int trim(char s[]);

int main(void)
{
  char s[] = "this is a string  ";

  // 移除字符末尾的空格
  trim(s);

  printf("%s", s);

  return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
  int n;

  // strlen 是 <string.h> 中的标准函数
  for (n = strlen(s) - 1; n >= 0; n--)
  {
    if ((s[n] != ' ') && (s[n] != '\t') && (s[n] != '\n'))
    {
      // 中断
      break;
    }
  }

  // 将空格转换为 \n
  s[n + 1] = '\n';
  return n;
}
