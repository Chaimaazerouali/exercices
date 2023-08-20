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
	while (specifiers[i].specStr)
	{
		if (*s == specifiers[i].specStr[0])
		{
			return (specifiers[i].funcPtr);
		}
		i++;
	}
	return (NULL);
}

