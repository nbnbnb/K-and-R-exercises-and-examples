#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, con't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

#define BUFFSIZE 100

// 用 static 声明限定外部变量与函数
// 可以将其后声明的对象的作用域限定为被编译源文件的剩余部分

// 通过 static 限定外部对象，可以达到隐藏外部对象的目的

// 静态变量
static int bufp = 0;

/* getop: get next operator or numberic operand */
int getop(char s[])
{

  // static 也可以用于声明内部变量
  // static 类型的内部变量同自动变量一样，是某个特定函数的局部变量，只能在改函数中使用

  // 但它与自动变量不同的是，不管其所在函数是否被调用
  // 它一直存在，二不像自动变量那样，随着所在函数的被调用和退出而存在和消失

  // 总结：static 类型的内部变量是一种只能在某个特定函数中使用但一直占据存储空间的变量

  static char buf[BUFFSIZE];

  int i, c;

  while ((s[0] = c = (bufp > 0) ? buf[--bufp] : getchar()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c; // not a number
  i = 0;
  if (isdigit(c)) // collect integer part
    while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
      ;
  if (c == '.') // collect fraction part
    while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
      ;
  s[i] = '\0';
  if (c != EOF)
    buf[bufp++] = c;
  return NUMBER;
}
