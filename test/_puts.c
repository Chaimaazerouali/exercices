#include "main.h"

/**
 * custom_puts - Print a string with newline.
 * @str: The string to print.
 *
 * Return: Number of characters printed.
 */
int custom_puts(char *str)
{
	char *a = str;

	while (*str)
		custom_putchar(*str++);
	return (str - a);
}

/**
 * custom_putchar - Write the character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1, and errno set appropriately.
 */
int custom_putchar(int c)
{
	static int i;
	static char buf[OUT_BUF_SIZE];

	if (c == BUF_FLUSH_MODE || i >= OUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH_MODE)
		buf[i++] = c;
	return (1);
}

