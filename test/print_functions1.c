#include "main.h"

/**
 * display_string - prints string
 * @args: argument pointer
 * @params: the parameter settings struct
 *
 * Return: number chars printed
 */
int display_string(va_list args, param_t *params)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = pad = str_length(str);
	if (params->precisionVal < pad)
		j = pad = params->precisionVal;

	if (params->minus)
	{
		if (params->precisionVal != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += custom_putchar(*str++);
		else
			sum += custom_puts(str);
	}
	while (j++ < params->widthVal)
		sum += custom_putchar(pad_char);
	if (!params->minus)
	{
		if (params->precisionVal != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += custom_putchar(*str++);
		else
			sum += custom_puts(str);
	}
	return (custom_putchar('%'));
}
/**
 * display_percent - prints string
 * @args: argument pointer
 * @params: the parameter settings struct
 *
 * Return: number chars printed
 */
int display_percent(va_list args, param_t *params)
{
	(void)args;
	(void)params;
	return (custom_putchar('%'));
}
