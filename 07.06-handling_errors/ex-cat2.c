#include <stdio.h>
#include <stdlib.h>

// 7.6 处理错误 —— stderr 和 exit

/* cat: concatenate files, version 1 */
int main(int argc, char *argv[])
{
  FILE *fp;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0]; // program name for errors

  if (argc == 1) // no args; copy standard input
  {
    filecopy(stdin, stdout);
  }
  else
  {
    while (--argc > 0)
    {
      if ((fp = fopen(*++argv, "r")) == NULL)
      {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      }
      else
      {
        filecopy(fp, stdout);
        fclose(fp);
      }
    }
  }

  // <stdio.h> 中的标准函数
  // 如果 stdout 中出现错误，则 ferror 函数返回一个非 0 值
  if (ferror(stdout))
  {
    // <stdio.h> 中的标准函数
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }

  // <stdlib.h> 中的标准函数
  // exit 为每个已打开的输出文件调用 fclose 函数
  // 以将缓冲区中所有输出写到相应的文件中
  exit(0);
}

/* fielcopey: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
