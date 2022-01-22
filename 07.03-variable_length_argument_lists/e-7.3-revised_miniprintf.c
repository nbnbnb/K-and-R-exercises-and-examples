/* Revise miniprintf to handle more of the other facilities of printf. */
#include <stdio.h>
#include <stdarg.h>

// 7.3 变长参数表

/* miniprintf: minimal printf with variable argument list */
// 省略号表示参数表中参数的数量和类型是可变的
void miniprintf(char *fmt, ...)
{
	// va_list 类型用于声明一个变量
	// 该变量将依次引用各参数
	va_list ap; // points to each unnamed arg in turn

	char *p, *sval;
	int ival;
	double dval;

	// 宏 va_start 将 ap 初始化为指向第一个无名参数的指针
	// 在使用 ap 之前，该宏必须被调用一次
	va_start(ap, fmt); // make ap point ot 1st unnamed arg

	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
		case 'i':
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'o':
			ival = va_arg(ap, int);
			printf("%o", ival);
			break;
		case 'X':
		case 'x':
			ival = va_arg(ap, int);
			printf("%x", ival);
			break;
		case 'u':
			ival = va_arg(ap, int);
			printf("%u", ival);
			break;
		case 'c':
			ival = va_arg(ap, int);
			printf("%c", ival);
			break;
		case 'G':
		case 'g':
		case 'E':
		case 'e':
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	// 清理宏
	va_end(ap); // clean up when done
}

int main(void)
{
	miniprintf("This is the %c\n", 's');
}
