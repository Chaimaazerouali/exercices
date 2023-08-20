#include "main.h"
/**
 * fetch_print_func - finds the format func
 * @s: the format string
 * @args: argument list
 * @params: the parameter settings struct
 *
 * Return: the number of bytes printed
 */
int fetch_print_func(char *s, va_list args, param_t *params)
{
	int (*funcPtr)(va_list, param_t *) = fetch_specifier(s);

	if (funcPtr)
		return (funcPtr(args, params));
	return (0);
}

/**
 * fetch_flag - finds the flag func
 * @s: the format string
 * @params: the parameter settings struct
 *
 * Return: if flag was valid
 */
int fetch_flag(char *s, param_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus = 1;
			break;
		case ' ':
			i = params->space = 1;
			break;
		case '#':
			i = params->hashtag = 1;
			break;
		case '-':
			i = params->minus = 1;
			break;
		case '0':
			i = params->zero = 1;
			break;
	}
	return (i);
}

