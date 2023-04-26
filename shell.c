#include <errno.h>
#include "simple_shell.h"
#define MAX_INPUT_LENGH 1024
#define MAX_ARGS 64
/**
 *main - represents the start code
 *
 *Return: (0) for success
 */
int main(void)
{
	char *input;
	char *args[MAX_ARGS];
	int num_args;

	do {
		print_str("my-shell$ ");
		input = my_getline();
		if (input == NULL)
		{
			print_str("Exiting my-shell\n");
			exit(EXIT_SUCCESS);
		}
			if (strlen(input) <= 1 || input[0] == '\n'
					{
					free(input);
					continue;
					}

					num_args = 0;
					args[num - args] = strtok(input, " \t\n");
					while (args[num_args] != NULL && num_args < MAX_ARGS - 1)
					{
					num_args++;
					args[num_args] = strtok(NULL, " \T\N");
					}
					args[num_args] = NULL;
					if (num_args == 0)
					{
					free(input);
					continue;
					}
					if (_strncmp(args[0], "cd") == 0)
					{
						cd(args[1]);
						continue;
					}
					execute_command(args);
					free(input);
	} while (1);
	print_str("EXITING my-shell\n");
	exit(EXIT_SUCCES);
}

