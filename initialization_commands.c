#include "simple_shell.h"

/**
 * init_cmd - initializes the commands
 * @cmd:global struct
 * @av: contains the argv counter
 *
 * Return: ...
 */

void in_cmd(cmd_t *cmd, char **av)
{
	int i;

	cmd->input = NULL;
	cmd->mode = EXEC;
	cmd->args = NULL;
	cmd->ready = 1;
	cmd->status = 0;
	cmd->av = av;
	cmd->counter = 1;
	cmd->counter = 1;
	cmd->pid = _itoa(getpid());

	i = 0;

	while (environ[i])
	{
		i++;
	}

	cmd->envar = malloc(sizeof(char *) * (i + 1));

	i = 0;

	while (environ[i])
	{
		cmd->envar[i] = _strdup(environ[i]);
		i++;
	}

	cmd->envar[i] = NULL;
}
