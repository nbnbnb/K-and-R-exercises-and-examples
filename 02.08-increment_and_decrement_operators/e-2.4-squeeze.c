/* Write an alternate version of squeeze(s1, s2), that deletes each character
   in s1 that matches any character in the string s2. */
#include <stdio.h>

// 2.8 自增运算符与自减运算符

// 练习：只要出现在 s2 中的字符，都在 s1 中删掉掉

// 最大支持 20 个字符
#define MAXLEN 20

void squeeze(char s1[], char s2[]);

int main(void)
{
  char s1[MAXLEN], s2[MAXLEN];

  printf("Enter the string: ");
  // 输入字符串
  // 回车结束
  scanf("%s", s1);

  printf("Enter the matching string: ");
  // 输入字符串
  // 回车结束
  scanf("%s", s2);

  // 求差集
  // s1 - s2
  squeeze(s1, s2);
  printf("The sqeezed string is: %s\n", s1);

  return 0;
}

void squeeze(char s[], char m[])
{
  int i, j, k;

  for (i = k = 0; s[i] != '\0'; ++i)
  {
    // 每次从 s2 开头扫描
    // 发现字符相等，则跳出
    for (j = 0; (m[j] != s[i]) && (m[j] != '\0'); ++j)
      ;

    // s2 到结尾了，还没有匹配的
    // 则保留下来
    if (m[j] == '\0')
    {
      // 先赋值
      // 再自增
      s[k++] = s[i];
    }
  }
  // 自增过了
  // 不需要再处理
  s[k] = '\0';
}
