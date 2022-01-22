#include <stdio.h>

// 7.5 文件访问

// 启动一个 C 程序语言时，操作系统环境负责打开 3 个文件
// 并将这个 3 个文件的指针提供给该程序

// stdin stdout stderr
// 在大多数环境中，stdin 指向键盘，stdout 和 stderr 指向显示器

/* cat: concatenate files, version 1 */
int main(int argc, char *argv[])
{
  // 声明 FILE 类型，这是一个 typedef
  FILE *fp;

  void filecopy(FILE *, FILE *);

  if (argc == 1) // no args; copy standard input
  {
    filecopy(stdin, stdout);
  }
  else
  {
    while (--argc > 0)
    {
      // fopen 是 <stdio.h> 中的标准函数
      if ((fp = fopen(*++argv, "r")) == NULL)
      {
        printf("cat: can't open %s\n", *argv);
        return 1;
      }
      else
      {
        // 文件打开成功
        // 开始拷贝
        // stdout 是标准输出流，也是文件
        filecopy(fp, stdout);

        // fclose 是 <stdio.h> 中的标准函数
        // 关闭文件
        fclose(fp);
      }
    }
  }

  return 0;
}

/* fielcopey: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  // getc 和 putc 都是 <stdio.h> 中的标准函数
  while ((c = getc(ifp)) != EOF)
  {
    putc(c, ofp);
  }
}
