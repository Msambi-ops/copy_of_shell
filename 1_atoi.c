#include "shell.h"

/**
* interactive - the funct return true when shell is interactive
* @info: this is struct address.
*
* Return: it returns 1 if interactive and 0 if not
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - the funct to check for a delimeter char
* @c: this is the character to be checked.
* @delim: this is the delimeter str.
* Return: returns 1 on true and 0 on false
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
* _isalpha - the funct to check for alphabetic char.
* @c: this is the character to be inputed,
* Return: it returns 1 if it is alphabetic, 0 otherwise.
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
* _atoi - this function convert a strng to an int
* @s: the str to be converted
* Return: 0 if there is no no. in str, converted no. otherwise.
*/
int _atoi(char *s)
{
		int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
