/* Write a program to compare two files, printing the first line where they differ. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 7.7 行输入和行输出
// fgets：从输入中读取行，读取的行将以 '\0' 结尾保存
// fputs：将一个字符串（不需要包含换行符）写入到一个文件

// gets 和 puts 的功能与 fgets 和 fputs 类似，但是它们时对 stdin 和 stdout 进行操作

#define MAXLINE 100

int main(int argc, char *argv[])
{
  FILE *f1, *f2;

  // 定义两个存储输入的字符数组
  char l1[MAXLINE], l2[MAXLINE];

  char *prog = argv[0];

  if (argc != 3)
  {
    printf("error: the program takes 2 arguments;\n");
    return 0;
  }
  else if ((f1 = fopen(*++argv, "r")) != NULL)
  {
    if ((f2 = fopen(*++argv, "r")) != NULL)
    {
      // 标准库提供的输入函数 fgets，和之前遇到的 getline 类似
      // 从 f1 中读取下一输入行，放入字符数组 l1 中
      while (fgets(l1, MAXLINE, f1) != NULL && fgets(l2, MAXLINE, f2) != NULL)
      {
        if (strcmp(l1, l2) != 0)
        {
          printf("%s", l1);
          printf("%s", l2);
          fclose(f1);
          fclose(f2);
          return 0;
        }
      }
    }
    else
    {
      fprintf(stderr, "%s can't open %s", prog, *argv);
      exit(1);
    }
  }
  else
  {
    fprintf(stderr, "%s can't open %s", prog, *argv);
    exit(1);
  }

  printf("Identical lines\n");
  return 0;
}
