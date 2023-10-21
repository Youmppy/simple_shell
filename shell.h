#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/* reads input */
char *read_input(void);
void freearray2D(char **arr);
char *duplicate_string(const char *str);
char **tokenizer(char *line);


#endif
