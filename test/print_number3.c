#include "main.h"
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
