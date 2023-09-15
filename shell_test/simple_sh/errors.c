#include "shell.h"

/**
 * my_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void my_eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
my_eputchar(str[i]);
i++;
}
}

/**
 * my_eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_eputchar(char c)
{
static int i;
static char buf[MY_WRITE_BUF_SIZE];

if (c == MY_BUF_FLUSH || i >= MY_WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != MY_BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * my_putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_putfd(char c, int fd)
{
static int i;
static char buf[MY_WRITE_BUF_SIZE];

if (c == MY_BUF_FLUSH || i >= MY_WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != MY_BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * my_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int my_putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += my_putfd(*str++, fd);
}
return (i);
}

