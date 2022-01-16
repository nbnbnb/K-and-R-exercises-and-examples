/* Write a function expand(s1,s2) that expands shorthand notations like a-z in the 
   string s1 into the equivalent complete lise abc...xyz in s2. Allow for letters of 
   either case and digits , and be prepared to handle cases like a-b-c and a-z0-9 
   and -a-z. Arrange that a leading or trailing - is taken literally. */
#include <stdio.h>
#include <ctype.h>

// 3.5 while 循环与 for 循环

#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main(void)
{
  char s1[MAXLEN], s2[MAXLEN], c;
  int i = 0;

  printf("Enter the string: ");

  while ((c = getchar()) != EOF)
  {
    s1[i++] = c;
  }

  s1[i] = '\0';

  expand(s1, s2);

  printf("\nExpanded :\n%s\n", s2);

  return 0;
}

// 输入 a-z
// 则输出这个区间的整个字符 abcdefghijklmnopqrstuvwxyz

// 输入 A-z
// 则输出 ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz

void expand(char s[], char t[])
{
  int i = 0, j = 0, k;

  // 此处把 i/j 自加成 1 了
  t[j++] = s[i++];

  while (s[i] != '\0')
  {

    // 这里使用了很多 <ctype.h> 中的标准函数

    // 判断是 "数字对" 还是 "字符对"
    if ((s[i] == '-') && (s[i + 1] != '\0') &&
        ((isdigit(s[i - 1]) && isdigit(s[i + 1])) ||
         (isalpha(s[i - 1]) && isalpha(s[i + 1]))))
    {

      // 此处 k 是从 a-z 中的 b 字符开始的
      // 因为上面已经复制过 a 字符了
      // 结束标志是 z 字符
      for (k = (s[i - 1] + 1); k <= s[i + 1]; k++)
      {
        // 每次复制一个
        t[j++] = k;
      }

      // 读取了两个字符
      // 例如 a-z 中的 -z
      i += 2;
    }
    else
    {
      // 如果不是
      // 则原样复制
      t[j++] = s[i++];
    }
  }

  // 使用的是 j++ 模式
  // 所有此处赋值最后的 EOF
  t[j] = '\0';
}
