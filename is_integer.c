#include "monty.h"

/**
 * isInteger - chacks if a string is integer
 * @str: string to check
 *
 * Return: 1 if true, otherwise 0
 */
int isInteger(const char *str)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
