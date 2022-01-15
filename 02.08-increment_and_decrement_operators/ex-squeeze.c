#include <stdio.h>

// 2.8 自增运算符与自减运算符

void squeeze(char s[], char ch);

int main(void)
{
  char s[] = "string";
  char c = 'n';

  squeeze(s, c);

  // strig
  printf("The new string: %s\n", s);

  return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], char c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
  {
    // 等于 c 的时候
    // 跳过（删除）
    if (s[i] != c)
    {
      // 先赋值
      // 后自增
      s[j++] = s[i];
    }
  }

  // 由于上面已经自增了
  // 所以最后的索引就是 j
  s[j] = '\0';
}
