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

/**
 * display_unsigned - Print unsigned integer numbers.
 * @args: Argument pointer.
 * @params: The parameter settings struct.
 *
 * Return: Number of bytes printed.
 */
int display_unsigned(va_list args, param_t *params)
{
	unsigned long val;

	if (params->lMod)
		val = (unsigned long)va_arg(args, unsigned long);
	else if (params->hMod)
		val = (unsigned short int)va_arg(args, unsigned int);
	else
		val = (unsigned int)va_arg(args, unsigned int);

	params->isUnsigned = 1;
	return (print_num_str(num_convert(val, 10, UNSIGNED_CONV, params), params));
}

/**
 * display_address - Print memory addresses.
 * @args: Argument pointer.
 * @params: The parameter settings struct.
 *
 * Return: Number of bytes printed.
 */
int display_address(va_list args, param_t *params)
{
	unsigned long int address = va_arg(args, unsigned long int);
	char *str;

	if (!address)
		return (custom_puts("(nil)"));

	str = num_convert(address, 16, UNSIGNED_CONV | TO_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';

	return (print_num_str(str, params));
}

