#include "simple_shell.h"

/**
 * _readwrite- input string.
 *
 * @is_eof: return value of getline function
 * @status: is interactive
 * Return:.....
 */
char *_readwrite(int status, int *is_eof)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	prompt(status);
	*is_eof = getline(&buffer, &bufsize, stdin);

	return (buffer);
}
