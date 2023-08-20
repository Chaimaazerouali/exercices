#include "main.h"
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

