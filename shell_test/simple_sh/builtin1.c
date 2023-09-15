#include "shell.h"

/**
 * my_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int my_history(my_info_t *info)
{
print_my_list(info->history);
return (0);
}

/**
 *  unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int  unset_alias(my_info_t *info, char *str)
{
char *p, c;
int ret;

p = my_strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_my_node_at_index(&(info->alias),
get_my_node_index(info->alias, my_node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(my_info_t *info, char *str)
{
char *p;

p = my_strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_my_node_end(&(info->alias), str, 0) == NULL);
}

/**
	 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(my_list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = my_strchr(node->str, '=');
for (a = node->str; a <= p; a++)
my_putchar(*a);
my_putchar('\'');
my_puts(p + 1);
my_puts("'\n");
return (0);
}
return (1);
}

/**
 * my_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_alias(my_info_t *info)
{
int i = 0;
char *p = NULL;
my_list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = my_strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(my_node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}

