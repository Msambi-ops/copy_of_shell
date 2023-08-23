#include "shell.h"

/**
* bfree - the function frees a ptr and NULL addresses.
* @ptr: the address of the ptr to free func.
* Return: the funct returns 1 if its freed 0 otherwise.
*/
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
