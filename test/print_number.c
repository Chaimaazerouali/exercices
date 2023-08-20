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

/**
 * print_num_str - prints a number with options
 * @str: the base number as a string
 * @params: the parameter settings struct
 *
 * Return: chars printed
 */
int print_num_str(char *str, param_t *params)
{
	unsigned int i = str_length(str);
	int neg = (!params->isUnsigned && *str == '-');

	if (!params->precisionVal && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precisionVal != UINT_MAX)
		while (i++ < params->precisionVal)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus)
		return (print_num_rshift(str, params));
	else
		return (print_num_lshift(str, params));
}

/**
 * print_num_rshift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter settings struct
 *
 * Return: chars printed
 */
int print_num_rshift(char *str, param_t *params)
{
	unsigned int n = 0, neg, neg2, i = str_length(str);
	char pad_char = ' ';

	if (params->zero && !params->minus)
		pad_char = '0';
	neg = neg2 = (!params->isUnsigned && *str == '-');
	if (neg && i < params->widthVal && pad_char == '0' && !params->minus)
		str++;
	else
		neg = 0;
	if ((params->plus && !neg2) ||
		(!params->plus && params->space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += custom_putchar('-');
	if (params->plus && !neg2 && pad_char == '0' && !params->isUnsigned)
		n += custom_putchar('+');
	else if (!params->plus && params->space && !neg2 &&
		!params->isUnsigned && params->zero)
		n += custom_putchar(' ');
	while (i++ < params->widthVal)
		n += custom_putchar(pad_char);
	if (neg && pad_char == ' ')
		n += custom_putchar('-');
	if (params->plus && !neg2 && pad_char == ' ' && !params->isUnsigned)
		n += custom_putchar('+');
	else if (!params->plus && params->space && !neg2 &&
		!params->isUnsigned && !params->zero)
		n +=  custom_putchar(' ');
	n += custom_puts(str);
	return (n);
}

/**
 * print_num_lshift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter settings struct
 *
 * Return: chars printed
 */
int print_num_lshift(char *str, param_t *params)
{
	unsigned int n = 0, neg, neg2, i = str_length(str);
	char pad_char = ' ';

	if (params->zero && !params->minus)
		pad_char = '0';
	neg = neg2 = (!params->isUnsigned && *str == '-');
	if (neg && i < params->widthVal && pad_char == '0' && !params->minus)
		str++;
	else
		neg = 0;

	if (params->plus && !neg2 && !params->isUnsigned)
		n += custom_putchar('+'), i++;
	else if (params->space && !neg2 && !params->isUnsigned)
		n += custom_putchar(' '), i++;
	n += custom_puts(str);
	while (i++ < params->widthVal)
		n += custom_putchar(pad_char);
	return (n);
}

