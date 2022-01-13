/* Write a program to "fold" long input lines into two or more shorter lines 
   after the last non-blank character that occurs before the n-th column of input. 
   Make sure your program does somthing intelligent with very long lines, and
   if there are no banks or tabs before the specified column. */

// 1.10 外部变量与作用域

// 练习：1-22 
// 编写一个程序，把较长的输入行 “折” 成短一些的两行或多行
// 折行的位置在输入行的第 n 列之前的最后一个非空格之后
#include <stdio.h>

// 5 个一折行
#define COLUMN 5

int main(void)
{
  int c, i, j, k;
  char line[COLUMN + 1];

  i = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\n') // if line new print string and reset counter
    {
      line[i] = c;
      line[i + 1] = '\0';
      printf("%s", line);
      i = 0; // reset counter
    }
    else if (i <= COLUMN - 1) // if characters have not pass the column limit
    {
      line[i] = c; // add the last read char to the string
      ++i;
    }
    else
    {
      k = 0;

      for (j = i - 1; (line[j] == ' ') && (j >= 0); --j) // go to the last non blank char
      {
        ++k;
      }

      line[j + 1] = '\0';
      printf("%s", line); // add NULL to the end and print string

      for (i = 0; i < k; ++i) // add spaces back and the last char
      {
        line[i] = ' ';
      }

      line[i] = c; // add char to the next string
      ++i;
    }
  }

  line[i] = '\0'; // print the last chars
  printf("%s\n", line);

  return 0;
}
