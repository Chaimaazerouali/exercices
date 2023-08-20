#include "main.h"
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
