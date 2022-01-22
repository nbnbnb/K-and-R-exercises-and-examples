/* Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s,t) copies the string t to the end of s. */
#include <stdio.h>

// 5.5 字符指针与函数
// 连接字符串
// 输出：Concatenated string: firstsecond
void str_cat(char *s1, char *s2);

int main(void)
{

  char *ps1, *ps2;
  char s3[] = "first", s4[] = "second";

  // 赋值指针地址
  ps1 = s3;
  // 赋值指针地址
  ps2 = s4;

  str_cat(ps1, ps2);

  // %s 传入字符数组指针地址即可
  printf("Concatenated string: %s", ps1);

  return 0;
}

// 传入源地址指针和目标地址指针
void str_cat(char *s1, char *s2)
{
  // 指针 "跑" 到 s1 的结尾
  for (; *s1 != '\0'; s1++)
    ;

  // 将 s2 的字符指针赋值给 s1
  // 下一个字符
  while ((*s1++ = *s2++) != '\0')
    ;
}
