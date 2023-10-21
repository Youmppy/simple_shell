#include "shell.h"

/**
 * main - Simple Shell main function
 * @argc: Count of arguments
 * @argv: Arguments
 * Return: 0 Always (success).
 */

int main(int ac, char **argv)
{
	char *input = NULL;
	char **command = NULL;
	int s = 0;
	int i = 0;
	(void) ac;

	while (1)
	{
		input = read_input();
		if (input == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (s); /* ctr+d */
		}

		free(input);

		command = tokenizer(input);
		if (!command)
			continue;

		for (i = 0; command[i]; i++)
		{
			printf("%s\n", command[i]);
			free(command[i]);
			command[i] = NULL;
		}
		free(command);
		command = NULL;
	}
}

