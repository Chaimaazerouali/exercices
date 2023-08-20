#include "main.h"

/**
 * convert_num - Convert a number to its string representation.
 * @num: The number to convert.
 * @base: The base to use for conversion.
 * @flags: Conversion flags.
 * @params: The parameter settings struct.
 *
 * Return: Pointer to the converted string.
 */
char *num_convert(long int num, int base, int flags, param_t *params)
{	
	static char *digitsArray;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;
	if (!(flags & UNSIGNED_CONV) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	digitsArray = flags & TO_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = digitsArray[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

