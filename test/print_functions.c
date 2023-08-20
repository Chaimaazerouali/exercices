#include "main.h"

/**
 * display_char - prints character
 * @args: argument pointer
 * @params: the parameter settings struct
 *
 * Return: number chars printed
 */
int display_char(va_list args, param_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

	if (params->minus)
		sum += custom_putchar(ch);
	while (pad++ < params->widthVal)
		sum += custom_putchar(pad_char);
	if (!params->minus)
		sum += custom_putchar(ch);
	return (sum);
}

/**
 * display_int - prints integer
 * @args: argument pointer
 * @params: the parameter settings struct
 *
 * Return: number chars printed
 */
int display_int(va_list args, param_t *params)
{
	long l;

	if (params->lMod)
		l = va_arg(args, long);
	else if (params->hMod)
		l = (short int)va_arg(args, int);
	else
		l = (int)va_arg(args, int);
	return (print_num_str(num_convert(l, 10, 0, params), params));
}

