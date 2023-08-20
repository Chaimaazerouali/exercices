#include "main.h"

/**
 * is_digit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * str_length - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int str_length(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

