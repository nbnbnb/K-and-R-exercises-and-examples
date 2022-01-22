/* Write versions of the library functions strncpy, strncat, and strncmp, which operate
   on at most the first n characters of their argument string strings. For example,
   strncpy(s,t,n) copies at most n characters of t to s. */
#include <stdio.h>

// 5.5 字符指针与字符串

// 字符串复制
// 注意：返回的是一个 char pointer
char *strn_cpy(char *p_dest, char *p_source, int n);
// 字符串连接
// 注意：返回的是一个 char pointer
char *strn_cat(char *p_dest, char *p_source, int n);
// 字符串对比
int strn_cmp(char *p_s1, char *p_s2, int n);

int main(void)
{

  char *s1, *s2;
  char s3[] = "fiast";
  char s4[] = "firbalaportocala";

  s1 = s3;

  // 前两个字符 fi 相等
  // 返回 0
  printf("%d\n", strn_cmp(s3, s4, 2));

  // fia 和  fir 不相等
  // 由于 a < r
  // 所以返回 -1
  printf("%d\n", strn_cmp(s3, s4, 3));

  // 从 s4 中复制 3 个字符到 s3 的结尾
  // 返回 fiastfir
  printf("%s\n", strn_cat(s3, s4, 3));

  // 从 s4 中复制 3 个字符，赋值给 s3
  // 返回 fir
  printf("%s\n", strn_cpy(s3, s4, 3));

  return 0;
}

// 返回字符数组指针
char *strn_cpy(char *p_dest, char *p_source, int n)
{
  int i;

  char *r;

  // 记录字符数组的初始地址（因为 p_dest 会变的）
  // 最后需要返回这个初始地址
  r = p_dest;

  // 将 p_source 中的 n 个字符
  // 拷贝到 p_dest 中
  for (i = 0; i < n && *p_source != '\0'; i++)
  {
    *p_dest++ = *p_source++;
  }

  // 设置 EOF（截断 p_dest）
  *p_dest = '\0';

  // 返回字符数组的初始地址
  return r;
}

// 返回字符数组指针
char *strn_cat(char *p_dest, char *p_source, int n)
{
  // 声明一个字符数组指针
  // 存储起始地址
  char *r;

  int i;

  // 记录字符数组的初始地址（因为 p_dest 会变的）
  // 最后需要返回这个初始地址
  r = p_dest;

  // 跑到 p_dest 的结尾
  for (; *p_dest != '\0'; p_dest++)
    ;

  // 开始附加
  for (i = 0; *p_source != '\0' && i < n; i++)
  {
    *p_dest++ = *p_source++;
  }

  // 设置结尾 EOF
  *p_dest = '\0';

  return r;
}

// 比较前 n 个字符
int strn_cmp(char *s, char *t, int n)
{
  int i;

  // 比较每一个字符
  // 相同，则下一个继续
  for (i = 0; i < n && (*s++ == *t++); i++)
    ;

  if (i == n)
  {
    // 全部字符匹配
    return 0;
  }
  else
  {
    // 没有全部匹配
    // 比较最后不相等的那个字符
    return (*(s - 1) > *(t - 1)) ? 1 : -1;
  }
}
