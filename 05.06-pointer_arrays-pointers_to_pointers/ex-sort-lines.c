#include <stdio.h>
#include <string.h>

// 5.6 指针数组以及指向指针的指针

/**

输入
1324324
dfgdfg
578
dfgj
sdfweff

对输入的行进行排序后

输出
1324324
578
dfgdfg
dfgj
sdfweff


 **/

#define MAXLINES 5000 // max #lines to be sorted

// 这个一个指针数组
char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *p_lineptr[], int nlines);

void writelines(char *p_lineptr[], int nlines);

void qsort(char *p_lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
  int nlines; // number of input lines read

  // 传递声明的指针数组
  // 读取输入的行，到 lineptr 中
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {

    // 对 lineptr 中的行进行排序
    qsort(lineptr, 0, nlines - 1);

    // 输出 lineptr 中的所有行
    writelines(lineptr, nlines);

    return 0;
  }
  else
  {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000 // max length of any input line
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *p_lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  //  读取行
  while ((len = getline(line, MAXLEN)) > 0)
  {
    // 分配字符
    // p 是起始地址指针
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
    {
      return -1;
    }
    else
    {
      line[len - 1] = '\0'; // delete newline
      // <string.h> 中的标准函数
      // 字符串拷贝
      strcpy(p, line);
      // 把拷贝后的初始地址，赋值到指针数组中
      p_lineptr[nlines++] = p;
    }
  }

  return nlines;
}

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

#define ALLOCSIZE 50000 // size of available space

// 分配一个字符数组
static char allocbuf[ALLOCSIZE]; // storage for alloc
// 下一个可用字符的地址
static char *allocp = allocbuf; // next free position

// 分配 n 个字符
char *alloc(int n)
{
  // 字符的初始地址指针 + 最大的字符数 = 最大地址指针
  // 最大地址指针 - 以分配地址指针 = 可以分配多少个字符
  if (allocbuf + ALLOCSIZE - allocp >= n) // if it fits
  {
    allocp += n;
    // 返回分配的起始地址
    return allocp - n;
  }
  else
  {
    return 0;
  }
}

// 输出行
/* writelies: wtire output lines */
void writelines(char *p_lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
  {
    printf("%s\n", p_lineptr[i]);
  }
}

// 快速排序
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  // 交换
  // 声明也可以在函数中设置
  void swap(char *v[], int i, int j);

  if (left >= right) // do nothing if array contains fewer than two elements
  {
    return;
  }

  // 交互左边和中间位置
  swap(v, left, (left + right) / 2);

  // last 从 left 开始
  last = left;

  // 从左到右扫描
  // 将最大的元素放在右边
  // last 表示
  for (i = left + 1; i <= right; i++)
  {
    // 判断字符串大小
    // <string.h> 系统函数
    if (strcmp(v[i], v[left]) < 0)
    {
      // 注意，是对比后
      // last 才自加

      swap(v, ++last, i);
    }
  }

  swap(v, left, last);

  // 左部分
  qsort(v, left, last - 1);
  // 右部分
  qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  // 由于 v 是一个指针数组
  // 所以通过索引得到的就是一个指针
  char *temp;
  // 此处交换的是指针的值
  // 而不是实际存储的值
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
