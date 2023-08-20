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
	return (sum);
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

/**
 * display_S - custom format specifier
 * @args: argument pointer
 * @params: the parameter settings struct
 *
 * Return: number chars printed
 */
int display_S(va_list args, param_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (custom_puts(NULL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += custom_putchar('\\');
			sum += custom_putchar('x');
			hex = num_convert(*str, 16, 0, params);
			if (!hex[1])
				sum += custom_putchar('0');
			sum += custom_puts(hex);
		}
		else
		{
			sum += custom_putchar(*str);
		}
	}
	return (sum);
}

