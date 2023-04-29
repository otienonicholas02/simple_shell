#include "simple_shell.h"

/**
 * main - Entry point of the shell
 *
 * @ac: A count
 * @av: A vector
 *
 * Return: (0) or (1) for success or failure.
 */
int main(int ac, char **av)
{
	cmd_t cmd;
	(void) ac;

	signal(SIGINT, handl_sigint);
	in_cmd(&cmd, av);
	_loop(&cmd);
	free_cmd(&cmd);
	return (cmd.status);
}

/**
 * _loop - function that loops the shell
 * @cmd: data relevant (av, input, args)
 *
 * Return: .....
 */
void _loop(cmd_t *cmd)
{
	int loop;
	int i_eof;
	char *input;

	loop = 1;

	do {
		input = _readwrite(1, &i_eof);
		if (i_eof != -1)
		{
			input = handl_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(cmd, input) == 1)
			{
				cmd->status = 2;
				free(input);
				continue;
			}

			input = parse_input(input, cmd);
			loop = apply_seperators(cmd, input);
			cmd->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}  while (loop == 1);
}
