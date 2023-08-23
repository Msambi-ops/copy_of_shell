#include "shell.h"

/**
* _strncpy - the function copies a str.
* @dest: this is the destination str to be copied to.
* @src: this is the source str.
* @n: the size of chars,
* Return: the function returns concatenated str.
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
**_strcat - the funct to concatenate 2 strs.
* dest: the 1st str.
* @src: the 2nd str.
* @n: the size of bytes to be used,
* Return: the funct returns the concatenated str.
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
**_strchr - the function to look for a char in a str.
* @s: this is the str to be parsed,
* @c: this is the char to be looked.
* Return: the funct returns (s) ptr to memory area s.
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
