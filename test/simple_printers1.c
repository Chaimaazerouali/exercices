#include "main.h"
/**
 * rot13_print - prints string in rot13
 * @args: string
 * @params: the parameter settings struct
 *
 * Return: number bytes printed
 */
int rot13_print(va_list args, param_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += custom_putchar(arr[index]);
		}
		else
			count += custom_putchar(a[i]);
		i++;
	}
	return (count);
}
