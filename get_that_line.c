#include "shell.h"

/**
 * assign_lineptr - functions that re-assigns a varaiable
 * @line_ptr: A buffer
 * @n: The size
 * @buffer: The string
 * @b:size of buffer.
 */

void assign_lineptr(char **line_ptr, size_t *n, char *buffer, size_t b)
{
          char **lineptr = line_ptr;
          char *buf = buffer;
          size_t *new = n;
         size_t c = b;

          if (*lineptr == NULL)
          {
                  if (c > 120)
                          *new = c;
                  else
                          *new = 120;
                 *lineptr = buf;
          }
          else if (*new < c)
          {
                  if (c > 120)
                          *new = c;
                  else
                         *new = 120;
                  *lineptr = buf;
          }
         else
          {
                 _strcpy(*lineptr, buf);
                  free(buf);
          }
 }

/**
 * _getline - functions reads the line
 * @line_ptr: A buffer
 * @n: The size of lineptr.
 * @stream: stream to read from.
 *
 * Return:number of bytes read.
 */

ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	size_t *new = n;
	char **lineptr = line_ptr;
	static ssize_t input;
	ssize_t ret = 0;
	char c = 'x';
	char *buffer = NULL;
	int r = 0;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, 120, input + 1);
		buffer[input] = c, input++;
	}
	buffer[input] = '\n';
	assign_lineptr(lineptr, new, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}








