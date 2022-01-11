/* verifies EOF and prints the value of EOF*/
// 1.5 字符输入/输出
#include <stdio.h>

int main(void)
{
  // 标准库提供的函数
  // getchar()：一次读一个字符
  // setchar()：一次写一个字符

  // EOF 是标准库中定义的一个常量，值是 -1

  // 由于 C 中，bool true 是用 1 表示的，所以此处 %d 输出就是 1
  // The valut of getchar() != EOF is: 1
  printf("The valut of getchar() != EOF is: %d\n", (getchar() != EOF));

  // 控制台暂停，输入任意一个字符，然后回车

  // EOF 是常量 -1
  // The value of EOF is: -1
  printf("\nThe value of EOF is: %d\n", EOF);

  return 0;
}
