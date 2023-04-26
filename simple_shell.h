#ifndef _SIMPLE_H
#define _SIMPLE_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int _strncmp(char *s1, char *s2, int n);
int print_str(char *str);
void execute_command(char *args[]);
/**
 *_strncmp - function that compares strings
 *
 *@s1: represents first string
 *
 *@s2: reprsents second string
 *
 *@n: represents third string
 *
 *Return: both strings
 */
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

/**
 *print_str - custom print function
 *
 *@str: string to be printed
 *
 *Return: length of function
 */

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

/**
 *execute_command - function that executes
 *
 *@args:represents number of arguements
 *
 */

void execute_command(char *args[])
{
	pid_t id;
	int status;

	pid = fork();
	if (pid == -1)
	{
		print_str("Error: Failed to fork(%s)\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		if (execyp(args[0], args) == -1)
		{
			print_str("Error: Failed to execute command (%s)\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		if (waitpid(pid, &statu, 0) == -1)
		{
			print_str("Error: Failed to wait for child process (%s)\n",
					strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
}
#endif
