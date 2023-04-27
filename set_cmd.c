#include "simple_shell.h"

/**
 *setcmd - execution
 *
 *@buf: buffer containing args
 *
 *@cmd: struct
 *@Return:...
 */

void setcmd(char *buf, cmd_t *cmd)
{
	if (!buf[0])
		exit(EXIT_FAILURE);

	cmd->mode = EXEC;
}
