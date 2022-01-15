#include <stdio.h>

// 2.7 类型转换
// 练习：把字符串转换位 10 进制数
int a_toi(char s[]);

// 练习
int main(void)
{
  // 10 进制数 281
  char s[] = "281s";

  printf("The string '%s' converted into int: %d\n", s, a_toi(s));
  return 0;
}

/* a_toi; convert string to integer */
int a_toi(char s[])
{
  int i, n;

  n = 0;

  // 如果是 0~9 中间的数字
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    // s[i] - '0' 刚好是 10 进制的值

    // 这里有个技巧
    // 如果发现后面还有合法的数字，则将前面的 n * 10
    // 例如 28 后面是 1
    // 那么 n = 10 * 28 + ('1' - '0') = 281
    n = 10 * n + (s[i] - '0');
  }
  return n;
}
