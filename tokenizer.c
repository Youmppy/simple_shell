#include "shell.h"
char **tokenizer(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char **command = NULL;
	int cpt = 0;
	int i = 0;

	if (!line)
		return (NULL);

	tmp = duplicate_string(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}

	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char*) * (cpt + 1));
	token = strtok(line, DELIM);

	while (token)
	{
		command[i] = duplicate_string(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}

