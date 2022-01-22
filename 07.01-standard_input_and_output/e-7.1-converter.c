/* Write a program that converts upper case to lower or lower case to upper, depending
   on the name it is invoked with as found in argv[0]. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 7.1 标准输入 / 输出

// 一个函数指针
// 函数签名为：输入 int，返回 int
void printc(int (*func)(int));

// 注意，此处读取的启动参数
int main(int argc, char *argv[])
{

  if (strcmp(argv[0], "lower") == 0)
  {
    // tolower 是 <ctype.h> 定义的系统函数
    printc(tolower);
  }

  if (strcmp(argv[0], "upper") == 0)
  {
    // toupper 是 <ctype.h> 定义的系统函数
    printc(toupper);
  }

  return 0;
}

void printc(int (*func)(int))
{
  char c;

  while ((c = getchar()) != EOF)
  {
    putchar(func(c));
  }
}
