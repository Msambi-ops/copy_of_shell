#include "shell.h"

/**
* _eputs - the funct to print an input str.
* @str: this is the str to be written on standard output.
* Return: the function returns nothing.
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
* _eputchar - print the char c to stderr.
* @c: this is the char to print.
*
* Return: the function returns 1 on success, -1 on error and errno is set.
*/
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _putfd - the function prints the char c to fd.
* @c: this is the char to print.
* @fd: the file descriptor to print to.
*
* Return: returns 1 on success -1 on error and errno set.
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _putsfd - the funct print an input  str.
* @str: the str to be printed.
* @fd: the file descriptor to print to,
* Return: the function returns the no. of chars put.
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
