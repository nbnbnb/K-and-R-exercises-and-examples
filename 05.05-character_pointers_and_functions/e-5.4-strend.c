/* Write the function strend(s,t), which returns 1 if the string t occurs at the
   end of the string s and zero otherwise. */
#include <stdio.h>

// 5.5 字符指针与字符串

// strend(s,t) 函数判断 t 是否为 s 的结尾
// 如果是，返回 1
// 如果不是，返回 0
int strend(char *p_s1, char *p_s2);

int main(void)
{

  char *p_s1, *p_s2;
  char s3[] = "first", s4[] = "rst";

  p_s1 = s3;
  p_s2 = s4;

  printf("%d", strend(p_s1, p_s2));
  return 0;
}

int strend(char *p_s1, char *p_s2)
{
  int n = 1;

  // p_s1 跑到 EOF
  for (; *p_s1 != '\0'; p_s1++)
    ;

  // p_s2 跑到 EOF
  for (; *p_s2 != '\0'; p_s2++)
  {
    // 计算 p_s2 的长度
    n++;
  }

  // 从后向前对比
  // 每匹配成功一个
  // 则 n-1
  // 最后 n 表示不匹配的字符数
  while (n > 0 && (*p_s1-- == *p_s2--))
  {
    n--;
  }

  // 如果有不匹配的字符数
  // 返回 0
  // 没有不匹配的字符数
  // 返回 1
  return (n > 0) ? 0 : 1;
}
