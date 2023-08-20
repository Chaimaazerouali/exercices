#include "main.h"

/**
 * _printf - Print formatted string.
 * @format: The format string.
 * 
 * Return: Number of bytes printed.
 */
int _printf(const char *format, ...)
{
    int total = 0;
    va_list args;
    char *current, *begin;
    param_t params = INIT_PARAMS;

    va_start(args, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);

    for (current = (char *)format; *current; current++)
    {
        set_params(&params, args);

        if (*current != '%')
        {
            total += custom_putchar(*current);
            continue;
        }

        begin = current;
        current++;

        while (fetch_flag(current, &params))
        {
            current++; /* Advance to next character */
        }

        current = fetch_width(current, &params, args);
        current = fetch_precision(current, &params, args);

        if (fetch_modifier(current, &params))
            current++;

        if (!fetch_specifier(current))
            total += print_range(begin, current, 
                                 params.lMod || params.hMod ? current - 1 : 0);
        else
            total += fetch_print_func(current, args, &params);
    }

    custom_putchar(BUF_FLUSH_MODE);
    va_end(args);

    return (total);
}

