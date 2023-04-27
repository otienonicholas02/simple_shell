#include "shell.h"
#include "simple_shell.c"
#include "convert_specifiers.c"
#include "convert_specifiers2.c"
#include "convert_specifiers3.c"
#include "get_that_line.c"
#include "malloc_functions.c"
#include "functions.c"
#include "separators.c"
#include "handle_exec.c"
#include "pid_functs.c"
#include "built_ins.c"
#include "handle_errors.c"




/**
 * main - Entry point of the shell
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: ....
 */
int main(int ac, char **av)
{
	cmd_t cmd;
	(void) ac;

	signal(SIGINT, handl_sigint);
	init_cmd(&cmd, av);
	rep_loop(&cmd);
	free_cmd(&cmd);
	return (cmd.status);
}

