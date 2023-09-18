#include "shell.h"

/**
 * input_buffer - buffers chained commands
 * @i: parameter struct
 * @b: address of buffer
 * @l: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buffer(my_info_t *i, char **b, size_t *l)
{
ssize_t rr = 0;
size_t len_p = 0;

if (!*l) /* if nothing left in the buffer, fill it */
{
/* bfree((void **)info->cmd_buf); */
free(*b);
*b = NULL;
signal(SIGINT, sigintHandler);
#if MY_USE_GETLINE
rr = getline(buf, &len_p, stdin);
#else
rr = my_getline(i, b, &len_p);
#endif
if (rr > 0)
{
if ((*b)[rr - 1] == '\n')
{
(*b)[rr - 1] = '\0';/* remove trailing newline */
rr--;

}
i->linecount_flag = 1;
remove_my_comments(*b);
build_my_history_list(i, *b, i->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*l = rr;
i->cmd_buf = b;
}
}
}
return (rr);
}

/**
 * get_my_input - gets a line minus the newline
 * @in: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_my_input(my_info_t *in)
{
static char *b; /* the ';' command chain buffer */
static size_t i, j, l;
ssize_t rr = 0;
char **buf_p = &(in->arg), *p;

my_putchar(MY_BUF_FLUSH);
rr = input_buffer(in, &b, &l);
if (rr == -1) /* EOF */
return (-1);
if (l) /* we have commands left in the chain buffer */
{
j = i; /* init new iterator to current buf position */
p = b + i; /* get pointer for return */

check_my_chain(in, b, &j, i, l);
while (j < l) /* iterate to semicolon or end */
{
if (is_my_chain(in, b, &j))
break;
j++;
}

i = j + 1; /* increment past nulled ';'' */
if (i >= l) /* reached end of buffer? */
{
i = l = 0; /* reset position and length */
in->cmd_buf_type = MY_CMD_NORM;
}
*buf_p = p; /* pass back pointer to current command position */
return (my_strlen(p)); /* return length of current command */
}

*buf_p = b; /* else not a chain, pass back buffer from my_getline() */
return (rr); /* return length of buffer from my_getline() */
}

/**
 * read_buffer - reads a buffer
 * @i: parameter struct
 * @b: buffer
 * @j: size
 *
 * Return: rr
 */
ssize_t read_buffer(my_info_t *i, char *b, size_t *j)
{
ssize_t rr = 0;

if (*j)
return (0);
rr = read(i->readfd, b, MY_READ_BUF_SIZE);
if (rr >= 0)
*j = rr;
return (rr);
}

/**
 * my_getline - gets the next line of input from STDIN
 * @i: parameter struct
 * @pr: address of pointer to buffer, preallocated or NULL
 * @lg: size of preallocated ptr buffer if not NULL
 *
 * Return: sm
 */
int my_getline(my_info_t *i, char **pr, size_t *lg)
{
static char b[MY_READ_BUF_SIZE];
static size_t j, l;
size_t k;
ssize_t r = 0, sm = 0;
char *p = NULL, *new_p = NULL, *c;

p = *pr;
if (p && lg)
sm = *lg;
if (j == l)
j = l = 0;

r = read_buffer(i, b, &l);
if (r == -1 || (r == 0 && l == 0))
return (-1);
c = my_strchr(b + j, '\n');
k = c ? 1 + (unsigned int)(c - b) : l;
new_p = my_realloc(p, sm, sm ? sm + k : k + 1);
if (!new_p) /* MALLOC FAILURE! */
return (p ? free(p), -1 : -1);

if (sm)
my_strncat(new_p, b + j, k - j);
else
my_strncpy(new_p, b + j, k - j + 1);

sm += k - j;
j = k;
p = new_p;

if (lg)
*lg = sm;
*pr = p;
return (sm);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sm: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sm)
{
my_puts("\n");
my_puts("$ ");
my_putchar(MY_BUF_FLUSH);
}

