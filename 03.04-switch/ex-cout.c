#include <stdio.h>

// 3.4 switch 语句

// 字符类型统计

int main(void)
{
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;

	for (i = 0; i < 10; i++)
	{
		// 初始化数组
		// 索引 0~9
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			// 字符 0~9 统计
			ndigit[c - '0']++;
			break;
		case ' ':
		case '\n':
		case '\t':
			// 空白字符统计
			nwhite++;
			break;
		default:
			// 其它字符统计
			nother++;
			break;
		}
	}

	printf("\ndigits: ");

	for (i = 0; i < 10; i++)
	{
		printf(" %d", ndigit[i]);
	}

	printf(", white space: %d, other: %d\n", nwhite, nother);

	return 0;
}
