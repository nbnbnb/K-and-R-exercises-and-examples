/* Define a macro swap(t,x,y) that interchanges two arguments of type t, 
   (block structure will help). */
#include <stdio.h>

// 4.11 C 预处理器
// 用任意字符串序列替代一个标记
// 编译过程中，单独执行的 “第一个” 步骤

/**

文件包含
#include "文件名"
    在源文件所在位置查找该文件
    没有找到
        根据相应的规则查找该文件，这个规则同具体的实现有关
#include <文件名>
    根据相应的规则查找该文件，这个规则同具体的实现有关


宏替换
#define 名字 替换文本

替换只是对记号进行，对括在引号中的字符串不起作用
  如果 YES 是一个通过 #define 指令定义过的名字
  则在 printf("YES") 或 YESMAN 中将 “不执行” 替换

宏定义也可以带参数，这样可以对不同的宏调用使用不同的替换文本

  定义
  #define max(A,B) ( (A) > B ? (A) : (B))

  语句
  x = max(p+q, r+s) ;

  替换为
  x = ((p+q) > (r+s) ? (p+q) : (r+s)) ;

  缺陷：如果表达式存在副作用（比如含有自增运算符或者输入/输出），则会出现不正确的情况
  max(i++ , j++) 它将对每个参数执行两次自增操作

  同时，还必须要注意，要适当使用圆括号以保证计算次序的正确性
  #define square(x)  x * x
  当用 square(z+1) 调用展开后，就会出现错误

优点：getchar 与 putchar 函数在实际中常常被定义为宏，避免处理字符串是调用函数所需的运行时开销

#undef 指令取消名字的宏定义，这样可以保证后续的调用是函数调用，而不是宏调用
#undef getchar
int getchar(void){ ... }

规则：参数名以 # 作为前缀则结果将被扩展为有实际参数替换该参数的 "带引号的字符串"
例如，可以将它与字符串连接运算符结合起来编写一个调试打印宏
  #define dprint(expr)  printf(#expr " = %g\n" , expr)

  dpring(x/y);

  替换为
  printf("x/y" " = &g\n", x/y);

  等价于（把字符串连起来）
  printf("x/y = &g\n", x/y);

在实际替换中，" 替换为 \"，\ 替换为 \\，因此替换后，都是合法字符串常量

## 连接实际参数
如果替换文本中的参数与 ## 相邻，则该参数将被实际参数替换，## 与前后的空白符将被删除，并对替换后的结果重新扫描

  #define paste(front,back) front ## back

  paste(name,1)

  name1

## 的嵌套规则比较难

条件包含

#if 语句对其中的 "常量""整型" 表达式（其中不能包含 sizeof、类型转换运算符或 enum 常量）进行求值
若该表达式的值不等于 0，则包含其后的各行
直到遇到 #endif、#elif 或 #else 语句为止
在 #if 语句中可以使用表达式 defined(name)，如果定义，返回 1，否则返回 0

---

#if !defined(HDR)
#define HDR



#endif

---

多条件处理

#if SYSTEM == SYSV
  #define HDR "sysv.h"
#elif SYSTEM == BSD
  #define HDR "bsd.h"
#elif SYSTEM == MSDOS
  #define HDR "msdos.h"
#else
  #define HDR "default.h"
#endif

#include HDR

---

另外两个便捷的预处理语句 #ifdef #ifndef，专门用来测试是否存在定义

#ifndef HDR
#define HDR
* hdr.h 文件的内容放在这里 *
#endif

---

    ** /

// 格式化前是这样的
// #define swap(t,x,y) {t temp; temp=(x); (x)=(y); (y)=temp;}
#define swap(t, x, y) \
  {                   \
    t temp;           \
    temp = (x);       \
    (x) = (y);        \
    (y) = temp;       \
  }

    int main(void)
{
  int x = 3, y = 7;

  swap(int, x, y);
  printf("x=%d, y=%d", x, y);
  return 0;
}
