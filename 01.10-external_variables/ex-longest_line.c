/* Rewrite of the longes-line program with *line*, 
 *longest* and *max* as external variables. */
// 1.10 外部变量与作用域
#include <stdio.h>

#define MAXLINE 1000

// 外部变量必须定义在函数之外
// 只能定义一次
// "编译程序" 将为它分配存储单元
int max;               // maximum lengths seen so far
char line[MAXLINE];    // current input line
char longest[MAXLINE]; // longest line saved here

// 兼容

// getline 与 copy 函数都不带参数，因此从逻辑上来讲，此处的原型应该是 getline() 与 copy()
// 但是为了与老版本的 C 程序兼容，ANSI C 语言把空参数看成老版本 C 语言的声明方式，并且对参数表不再进行任何检查

// 结论：在 ANSI C 中如果要声明空参数表，则必须使用关键字 void 进行显式声明

int getline(void);
void copy(void);

/* print longest input line; specialized version */
int main(void)
{
  int len;

  // 每个需要访问外部变量的函数中
  // 必须声明相应的外部变量

  // 隐式声明的条件：外部变量的定义出现在使用它的函数之前

  /*
    在通常的做法中，所有外部变量的定义都放在源文件的开始处，这样就可以省略 extern 声明

    如果程序包含在多个源文件中，而某个变量在 file1 文件中定义、在 file2 和 file3 文件中使用
    那么在文件 file2 与 file3 中就需要使用 extern 声明来建立该变量与其定义之间的联系

    人们通常把变量和函数的 extern 声明放在一个单独的文件中（习惯上称为头文件）
    并在每个源文件的开头使用 #include 语句把所要用的头文件包含进来

    后缀为 .h 约定为头文件的扩展名

    示例：标准库 <stdio.h>

  */

  // 用 extern 语句显式声明（也可以隐式声明）
  extern int max;
  extern char longest[];

  max = 0;

  while ((len = getline()) > 0)
  {
    if (len > max)
    {
      max = len;
      copy();
    }
  }

  if (max > 0) // there was a line
  {
    printf("%s\n", longest);
  }

  return 0;
}

/* getline: specialized version */
int getline(void)
{
  int c, i;
  extern char line[];

  for (i = 0; (i < MAXLINE - 1) && ((c = getchar()) != EOF) && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = '\0';
    // 换行也是字符个数
    ++i;
  }

  // EOF（不算字符个数 ）
  line[i] = '\0';

  return i;
}

/* copy: specialized version*/
void copy(void)
{
  int i;

  // 每个需要访问外部变量的函数中
  // 必须声明相应的外部变量

  // 用 extern 语句显式声明（也可以通过上下文隐式声明）
  extern char line[], longest[];

  i = 0;

  while ((longest[i] = line[i]) != '\0')
  {
    i++;
  }
}
