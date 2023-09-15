#include "shell.h"
/**
 * clear_my_info - initializes info_t struct
 * @info: struct address
 */
void clear_my_info(my_info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
 * set_my_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_my_info(my_info_t *info, char **av)
{
int i = 0;

info->fname = av[0];
if (info->arg)
{
info->argv = my_strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = my_strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;

replace_my_alias(info);
replace_my_vars(info);
}
}

/**
 * free_my_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void  free_my_info(my_info_t *info, int all)
{
my_ffree(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_my_list(&(info->env));
if (info->history)
free_my_list(&(info->history));
if (info->alias)
free_my_list(&(info->alias));
my_ffree(info->my_environ);
info->my_environ = NULL;
my_bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
my_putchar(MY_BUF_FLUSH);
}
}

