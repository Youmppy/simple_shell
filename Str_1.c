#include "shell.h"

/**
 * This function duplicates a string.
 * 
 * @param str The string to be duplicated
 * 
 * @return Pointer to the duplicated string
 */
char *duplicate_string(const char *str)
{
	int length = 0;
	char *duplicate;

	if (str == NULL)
		return NULL;

	// Calculate the length of the string
	while (*str++)
		length++;

	// Allocate memory for the duplicated string
	duplicate = malloc(sizeof(char) * (length + 1));
	if (!duplicate)
		return NULL;

	// Copy the string in reverse order to the duplicated string
	for (length++; length--;)
		duplicate[length] = *--str;

	return duplicate;
}

void freearray2D(char **arr)
{
	int i;
	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

