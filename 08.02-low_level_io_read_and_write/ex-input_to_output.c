#include <stdio.h>
#include <unistd.h>

// 8.2 低级 I/O —— read 和 write

/* copy input to output */
int main(void)
{
  // BUFSIZ = 512
  char buf[BUFSIZ];
  int n;

  // 带缓冲区
  // 一次读取输入的字符到 buf 中
  // n 表示输入的字符个数（带换行/回车符）
  while ((n = read(0, buf, BUFSIZ)) > 0)
  {
    // 输入到 stdout
    write(1, buf, n);
  }

  return 0;
}
