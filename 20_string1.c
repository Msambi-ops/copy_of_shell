#include "shell.h"
/**
* _strcpy - the funct to copy a str.
* @dest: the destination.
* @src: the source.
* Return: the funct returns a ptr to destination.
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
* _strdup - the funct duplicates a str.
* @str: this is the str to duplicate.
* Return: the funct returns a ptr to the duplicated str.
*/
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--; )
		ret[length] = *--str;
	return (ret);
}

/**
* _puts - the funct prints an input str.
* @str: the str to be printed.
* Return: the function returns nothing.
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
* _putchar - thr funct writes the char c to stdout,
* @c: the char to print,
* Return: 1 on success.
* on error, returns -1, and errno is set.
*/
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
