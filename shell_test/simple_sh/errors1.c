#include "shell.h"

/**
 * my_erratoi - converts a string to an integer
 * @sr: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int my_erratoi(char *sr)
{
int j = 0;
unsigned long int r = 0;

if (*sr == '+')
sr++;
for (j = 0; sr[j] != '\0'; j++)
{
if (sr[j] >= '0' && sr[j] <= '9')
{
r *= 10;
r += (sr[j] - '0');
if (r > INT_MAX)
return (-1);
}
else
return (-1);
}
return (r);
}

/**
 * print_my_error - prints an error message
 * @in: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_my_error(my_info_t *in, char *estr)
{
my_eputs(in->fname);
my_eputs(": ");
print_my_d(in->line_count, STDERR_FILENO);
my_eputs(": ");
my_eputs(in->argv[0]);
my_eputs(": ");
my_eputs(estr);
}

/**
 * print_my_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @f: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_my_d(int input, int f)
{
int (*my_putchar)(char) = my_putchar;
int j, c = 0;
unsigned int a, ct;

if (f == STDERR_FILENO)
my_putchar = my_eputchar;
if (input < 0)
{
a = -input;
my_putchar('-');
c++;
}
else
a = input;
ct = a;
for (j = 1000000000; j > 1; j /= 10)
{
if (a / j)
{
my_putchar('0' + ct / j);
c++;
}
ct %= j;
}
my_putchar('0' + ct);
c++;

return (c);
}

/**
 * convert_my_number - converter function, a clone of itoa
 * @nm: number
 * @b: base
 * @fl: argument flags
 *
 * Return: string
 */
char *convert_my_number(long int nm, int b, int fl)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = nm;

if (!(fl & MY_CONVERT_UNSIGNED) && nm < 0)
{
n = -nm;
sign = '-';
}
array = fl & MY_CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % b];
n /= b;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * remove_my_comments - function replaces first instance of '#' with '\0'
 * @b: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_my_comments(char *b)
{
int j;

for (j = 0; b[j] != '\0'; j++)
if (b[j] == '#' && (!j || b[j - 1] == ' '))
{
b[j] = '\0';
break;
}
}

