#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("#cisfun$ ");

		if (fgets(command, sizeof(command), stdin) == NULL) {
			break; // Exit on Ctrl+D
		}

		command[strcspn(command, "\n")] = '\0'; // Remove trailing newline

		if (strlen(command) == 0) {
			continue; // Skip empty lines
		}

		pid_t pid = fork();

		if (pid == -1) {
			perror("fork");
			exit(1);
		}

		if (pid == 0) { // Child process
			if (execlp(command, command, (char *)NULL) == -1) {
				perror(command);
				exit(2);
			}
		} else { // Parent process
			wait(NULL);
		}
	}

	return 0;
}
