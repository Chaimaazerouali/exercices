#include "main.h"
/**
 * display_HEX - Print unsigned hex numbers in uppercase.
 * @args: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int display_HEX(va_list args, param_t *params)
{
	unsigned long val;
	int count = 0;
	char *str;

	if (params->lMod)
		val = (unsigned long)va_arg(args, unsigned long);
	else if (params->hMod)
		val = (unsigned short int)va_arg(args, unsigned int);
	else
		val = (unsigned int)va_arg(args, unsigned int);

	str = num_convert(val, 16, UNSIGNED_CONV, params);
	if (params->hashtag && val)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->isUnsigned = 1;
	return (count += print_num_str(str, params));
}

