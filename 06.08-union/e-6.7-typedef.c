#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 6.7 类型定义

// C 语言提供了一个称为 typedef 的功能
// 它用来建立新的数据类型名

// typedef 类似于 #define 语句
// 但由于 typedef 是由编译器解释的，因此它的文本替换功能要超过预处理器

// typedef 声明并没有创建一个新类型，它只是为某个已存在的类型增加了一个新的名称而已

// 示例：定义一个字符串
typedef char *String;

// 示例：定义类型 PFI 是 "一个指向函数的指针，该函数具有两个 char * 类型的参数，返回类型为 int"
typedef int (*PFI)(char *, char *);

typedef struct tnode *Treeptr;

typedef struct tnode
{                      /* the tree node: */
  char *word;          /* points to the text */
  int count;           /* number of occurrences */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
} Treenode;

// Treenode 是一个结构
// Treeptr 是指向该结构的指针

int main(void)
{

  String hello = "Hello World!\n";

  // 原始声明方式
  struct tnode n1;

  // typedef 声明方式
  Treenode n2;

  n2.count = 1;
  n1.count = 1;

  printf(hello);

  return 0;
}
