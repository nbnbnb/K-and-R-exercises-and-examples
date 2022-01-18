/* Add commands to print the top element of the stack without poping, to duplicate
   it, and to swap the top two elements. Add a command to clear the stack.  */

/* Add commands for handling variables. (It's easy to provide twenty six variables
   with single-letter names.) Add a variable for the most recently printed value. */
#include <stdio.h>
#include <stdlib.h> // for atof()
#include <math.h>	// for fmod()

#define MAXOP 100	  // max size of operand or operator
#define NUMBER '0'	  // signal that a number wes found
#define PRINT 'p'	  // print the element witout poping
#define DUPLICATE 'd' // duplicate element
#define SWAP 's'	  // swap the top two elements
#define CLEAR 'c'	  // clear the stack
#define VARIABLE 'x'  // name of the variable for the latest printed value

int getop(char[]);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear_stack(void);

double x;
/* reverse Polish calculator */
int main(void)
{
	int type, operator;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			operator= 1;
			push(atof(s));
			break;
		case VARIABLE:
			operator= 1;
			push(x);
			break;
		case '+':
			operator= 1;
			push(pop() + pop());
			break;
		case '-':
			operator= 1;
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			operator= 1;
			push(pop() * pop());
			break;
		case '/':
			operator= 1;
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			break;
		case '%':
			operator= 1;
			op2 = pop();
			if (op2 != 0)
				push(fmod(pop(), op2));
			break;
		case PRINT:
			operator= 0;
			print();
			break;
		case DUPLICATE:
			operator= 0;
			duplicate();
			break;
		case SWAP:
			operator= 0;
			swap();
			break;
		case CLEAR:
			operator= 0;
			clear_stack();
			break;
		case '\n':
			if (operator)
			{
				x = pop();
				printf("\t%.8g\n", x);
			}
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100
#include <string.h>

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

/* print: prints without poping*/
void print(void)
{
	x = val[sp - 1];
	printf("%g\n", x);
}

/* duplicate: duplicates the last element */
void duplicate(void)
{
	push(val[sp]);
}

/* swap: swaps the top 2 elements */
void swap()
{
	double temp;
	temp = val[sp - 2];
	val[sp - 2] = val[sp - 1];
	val[sp - 1] = temp;
}
/* clear_stack: clears the stack */
void clear_stack(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numberic operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; // not a number
	i = 0;
	if (isdigit(c)) // collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') // collect fraction part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE]; // buffer for ungetch
int bufp = 0;		// next free posotion in buf

int getch(void) // get a (possibly pushed back) character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push back on input
{
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
