#include <stdio.h>

// 2.3 常量

int str_len(char s[]);

int main(void)
{

  // lenght == 16
  char s[] = "This is a string";

  printf("The length of the string is: %d", str_len(s));

  return 0;
}

/* strlen: return length of s */
int str_len(char s[])
{
  int i;

  i = 0;

  // 与标准库的实现一样
  // 长度不包括末尾的 '\0'

  while (s[i] != '\0')
  {
    ++i;
  }
  return i;
}
