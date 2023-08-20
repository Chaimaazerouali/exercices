#include "main.h"

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

