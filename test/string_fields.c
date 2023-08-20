#include "main.h"

/**
 * fetch_precision - gets the precision from the format string
 * @format: the format string
 * @params: the parameter settings struct
 * @args: the argument list
 *
 * Return: new pointer
 */
char *fetch_precision(char *format, param_t *params, va_list args)
{
	int d = 0;

	if (*format != '.')
		return (format);
	format++;
	if (*format == '*')
	{
		d = va_arg(args, int);
		format++;
	}
	else
	{
		while (is_digit(*format))
			d = d * 10 + (*format++ - '0');
	}
	params->precisionVal = d;
	return (format);
}

