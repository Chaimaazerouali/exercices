#include "shell.h"

/**
 * my_exit - exits the shell
 * @i: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int my_exit(my_info_t *i)
{
int exitcheck;

if (i->argv[1]) /* If there is an exit arguement */
{
exitcheck = my_erratoi(i->argv[1]);
if (exitcheck == -1)
{
i->status = 2;
print_my_error(i, "Illegal number: ");
my_eputs(i->argv[1]);
my_eputchar('\n');
return (1);
}
i->err_num = my_erratoi(i->argv[1]);
return (-2);
}
i->err_num = -1;
return (-2);
}

