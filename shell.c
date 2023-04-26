#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "simple_shell.h"

#define MAX_INPUT_LENGH 1024
#define MAX_ARGS 64

int main()
{
	char *input;
	char *args[MAX_ARGS];
	int num_args;

	do {
		/* step 2a: Print the prompt */
		input = my_getline();
		if (input == NULL)
		{
			/* Handle ctrl+D */
			print_str("Exiting my-shell\n");
			exit(EXIT_SUCCESS);
		}


			if (strlen(input) <= 1 || input[0] == '\n'
					{
					free(input);
					continue;
					}

					/* step 2d: Parse the input to the command name */
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

					/* calling the cd command */

					if (_strncmp(args[0], "cd") == 0)
					{	
						cd(args[1]);
						continue;
					}

					/* step 2f: Search for command inthe current directory */
					execute_command(args);
					free(input);
	} while (1);
	print_str("EXITING my-shell\n");
	exit(EXIT_SUCCES);
}

