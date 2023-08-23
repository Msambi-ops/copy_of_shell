#include "shell.h"

/**
* _strlen - the function to return the length of the str.
* @s: the str whose the length is checked.
* Return: the function returns the int length of str.
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
* _strcmp - the function compares two strings.
* @s1: the first str.
* @s2: the sec str.
* Return: -ve if s1 < s2 +ve if s1 > s2 and 0 if s1 == s2.
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - the funct to check if needle starts with haystack.
* @haystack: the str to look for.
* @needle: the substr to find.
* Return: the funct returns address of next char of haystack or NULL.
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - the funct to concatenate two strings.
* @dest: this is the dest buffer.
* @src: this is the src buffer.
* Return: the funct returns a ptr to dest buffer.
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

