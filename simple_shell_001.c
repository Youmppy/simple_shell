#include "shell.h"

void run_shell() {
	char input[MAX_INPUT_SIZE];

	while (1) {
		printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL) {
			printf("\n");
			break; // Handle Ctrl+D (end of file)
		}

		input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

		if (strcmp(input, "exit") == 0) {
			break; // Exit the shell
		}

		pid_t child_pid = fork();

		if (child_pid == -1) {
			perror("Fork error");
			exit(1);
		}
		if (child_pid == 0) {
			// Child process
			if (execlp(input, input, NULL) == -1) {
				perror(input);
				exit(2);
			}
		} else {
			// Parent process
			int status;
			wait(&status);
		}
	}
}

int main(void) {
	run_shell();
	return 0;
}

