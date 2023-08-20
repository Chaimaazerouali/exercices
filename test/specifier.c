#include "main.h"

/**
 * fetch_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*fetch_specifier(char *s))(va_list args, param_t *params)
{
		spec_t specifiers[] = {

		{"c", display_char},
		{"d", display_int},
		{"i", display_int},
		{"s", display_string},
		{"%", display_percent},
		{"b", display_binary},
		{"o", display_octal},
		{"u", display_unsigned},
		{"x", display_hex},
		{"X", display_HEX},
		{"p",  display_address},
		{"S", display_S},
		{"r", reverse_print},
		{"R", rot13_print},
		{NULL, NULL}
	};
	int i = 0;
	{
		if (*s == specifiers[i].specStr[0])
		{
			return (specifiers[i].funcPtr);
		}
		i++;
	}
	return (NULL);
}

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
	int (*f)(va_list, param_t *) = fetch_specifier(s);

	if (f)
		return (f(args, params));
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

/**
 * fetch_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameter settings struct
 *
 * Return: if modifier was valid
 */
int fetch_modifier(char *s, param_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params-> hMod = 1;
		break;
	case 'l':
		i = params->lMod = 1;
		break;
	}
	return (i);
}

/**
 * fetch_width - gets the width from the format string
 * @s: the format string
 * @params: the parameter settings struct
 * @args: the argument list
 *
 * Return: new pointer
 */
char *fetch_width(char *s, param_t *params, va_list args)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(args, int);
		s++;
	}
	else
	{
		while (is_digit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->widthVal = d;
	return (s);
}

