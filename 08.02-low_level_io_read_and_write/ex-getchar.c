#include <stdio.h>
#include <unistd.h>

// 8.2 低级 I/O —— read 和 write

int getchar2(void);

int main(void)
{
  printf("%c\n", getchar2());

  return 0;
}

/* getchar2: simple buffered version of getchar*/
int getchar2(void)
{
  static char buf[BUFSIZ];
  static int n = 0;

  if (n == 0) // buffer is empty
  {
    // read 是系统函数

    // 第一个参数是文件描述符
    // 第二个参数是程序中存放都或写数据的字符数组
    // 第三个参数是要传输的字节数

    // 0 表示 stdin
    n = read(0, buf, sizeof buf);
  }

  // bufp 是数组的开始指针
  // 返回输入额第一个字符
  // 注意，此处返回的是 unsigned char，表示 0~255
  // char 表示的是 -127~127
  return (--n >= 0) ? (unsigned char)*buf : EOF;
}
