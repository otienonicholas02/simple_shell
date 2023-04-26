#ifndef _SIMPLE_H
#define _SIMPLE_H



int _strncmp(char *s1, char *s2, int n);
int print_str(char *str);
void execute_command(char *args[]);



int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	if (i == n || s1[i] == s2[i])
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

int print_str(char *str)
{
	if (str == NULL)
	{
		return (-1);
	}
	int len = 0;

	while (*str != '\0')
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}

void execute_command(char *args[])
{
	pid_t id;
	int status;

	/* step 2g i: Fork a new process */
	pid = fork();
	if (pid = -1)
	{
		printf("Error: Failed to fork(%s)\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* In the child process */

		/* step 2g ii: Execute he command using execyp() and pass the environment variables */

		if (execyp(args[0], args) == -1)
		{
			printf("Error: Failed to execute command (%s)\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* in the parent */
		/* step 2g iii: Wait for the child process to finish executing */

		if (waitpid(pid, &statu, 0) == -1)
		{
			printf("Erro: Failed to wait for child process (%s)\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
}
#endif
