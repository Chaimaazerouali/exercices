#include "main.h"
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
