/* Write the function any(s1, s2), which returns the first location in the string 
   s1 where any character form the string s2 occurs, or -1 if s1 contains no characters
   from s2. */

// 2.8 自增运算符与自减运算符

// 练习：判断 s2 中是否出现过 s1 中的字符
// 如果出现过，返回 s1 中第一次出现改字符的索引
// 否则，返回 -1

#include <stdio.h>

#define MAXLEN 20

int any(char s1[], char s2[]);

int main(void)
{
  char s1[MAXLEN], s2[MAXLEN];

  printf("Enter the string: ");
  scanf("%s", s1);

  printf("Enter the matching string: ");
  scanf("%s", s2);

  printf("The first position is:  %d\n", any(s1, s2));

  return 0;
}

int any(char s[], char m[])
{
  int i, j;

  for (i = 0; s[i] != '\0'; ++i)
  {
    // 每次 s2 都要从头扫描
    for (j = 0; m[j] != '\0'; ++j)
    {
      // 如果出现
      // 返回 s1 的当前索引
      if (s[i] == m[j])
      {
        return i;
      }
    }
  }

  return -1;
}
