/* Rewrite the function lower, which converts upper case letters to lower case, 
   with a conditional expression instead of if-else. */
#include <stdio.h>

// 2.11 条件表达式

int lower(int ch);

int main(void)
{
  char s[] = "lsk L";
  int i;

  for (i = 0; s[i] != '\0'; i++)
  {
    putchar(lower(s[i]));
  }

  printf("\n");
}

// 将字符转换为小写
int lower(int c)
{
  // 由于小写大大写的 ASCII 码间隔是 32（小写的在后面，更大）
  // 所以将 ASCII + 32 就可以得到对应的小写 ASCII 字符
  return ((c <= 'Z') && (c >= 'A')) ? (c + 32) : c;
}
