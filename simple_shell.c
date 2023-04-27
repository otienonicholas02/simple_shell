#include "shell.h"


/**
 * init_cmd - initialize shell vars
 * @cmd: struct contain shell global vars
 * @av: argv
 *
 * Return: no return
 */
void init_cmd(cmd_t *cmd, char **av)
{
	int i = 0;

	cmd->input = NULL;
	cmd->mode = EXEC;
	cmd->args = NULL;
	cmd->ready = 1;
	cmd->status = 0;
	cmd->av = av;
	cmd->counter = 1;
	cmd->pid = _itoa(getpid());

	for (i = 0; environ[i]; i++)
		;

	cmd->envar = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
		cmd->envar[i] = _strdup(environ[i]);

	cmd->envar[i] = NULL;
}



/**
 * runcmd - runs the commands
 *
 * @dir: directory of the command to execute
 * @input: the input string
 * @cmd: the command struct
 * Return: 1 on success and 0 on failure
 */
void runcmd(char *dir, char **input, cmd_t *cmd)
{
	if (input[0] == NULL)
		exit(EXIT_FAILURE);

	switch (cmd->mode)
	{
		case EXEC:
			if (execve(dir, input, cmd->envar) < 0)
				t_error("No such file or directory\n");
			break;
	}

	exit(EXIT_SUCCESS);
}


/**
 *rep_loop - function loop inifinite
 *
 *@cmd: represents the command
 *
 */

void rep_loop(cmd_t *cmd)
{
	int is_looping;
	int is_eof;
	char *user_input;

	is_looping = 1;

	do {
		user_input = _readwrite(1, &is_eof);
		if (is_eof != -1)
		{
			user_input = handl_comment(user_input);
			if (user_input == NULL)
				continue;
			if (check_syntax_error(cmd, user_input) == 1)
			{
				cmd->status = 2;
				free(user_input);
				continue;
			}
			user_input = parse_input(user_input, cmd);
			is_looping = apply_seperators(cmd, user_input);
			cmd->counter += 1;
			free(user_input);
		}
		else
		{
			is_looping = 0;
			free(user_input);
		}
	} while (is_looping == 1);
}


/**
 * setcmd - sets the mode of execution
 *
 * @buf: the buffer containing the arguments
 * @cmd: the command struct
 * Return: nothing
 */
void setcmd(char *buf, cmd_t *cmd)
{
	if (!buf[0])
		exit(EXIT_FAILURE);

	cmd->mode = EXEC;
}



