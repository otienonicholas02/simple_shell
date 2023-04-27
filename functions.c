#include "shell.h"

/**
 * scan_vars - function for typed varaibles is $$ or $?
 *
 * @h: reps the linked list
 * @input: input string
 * @status: last status of the Shell
 * @cmd: the data
 * Return: ....
 */
int scan_vars(list_t **h, char *input, char *status, cmd_t *cmd)
{
	int i, j, stlen, pid_len;

	stlen = _strlen(status);
	pid_len = _strlen(cmd->pid);

	for (i = 0, j = 1; input[i]; i++, j++)
	{
		if (input[i] == '$')
		{
			switch (input[j])
			{
				case '?':
					add_node_end(h, 2, status, stlen), i++;
					break;
				case '$':
					add_node_end(h, 2, cmd->pid, pid_len), i++;
					break;
				case ' ':
				case '\n':
				case '\0':
				case ';':
				case '\t':
					add_node_end(h, 0, NULL, 0);
					break;
				default:
					evar_check(h, input + i, cmd);
					break;
			}
		}
	}

	return (i);
}




/**
 * replaced_input - function replaces input
 *
 * @head: reps linked list
 * @input: input
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(list_t **head, char *input, char *new_input, int nlen)
{
	list_t *indx;
	int i;
	int j;
	int k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->var_len) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->var_len && !(indx->len_val))
			{
				for (k = 0; k < indx->var_len; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->var_len);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 *evar_check - typed var is an env
 *
 *@head: linked list
 *@input: input sting
 *@cmd: struct varaiable
 *Return: ...
 */

void evar_check(list_t **head, char *input, cmd_t *cmd)
{
	char **_env;
	int i, j, k, val;

	_env = cmd->envar;

	for (i = 0; _env[i]; i++)
	{
		for (k = 1, j = 0; _env[i][j]; j++)
		{
			if (_env[i][j] == '=')
			{
				val = _strlen(_env[i] + j + 1);
				add_node_end(head, k, _env[i] + j + 1, val);
				return;
			}
			if (input[k] == _env[i][j])
				k++;
			else
				break;
		}
	}

	for (k = 0; input[k]; k++)
	{
		if (input[k] == ' ' || input[k] == '\t' ||
		input[k] == ';' || input[k] == '\n')
			break;
	}

	add_node_end(head, k, NULL, 0);
}


/**
 *parse_input - function variable
 *
 *@input:the string
 *
 *@cmd: the structure
 *
 *Return: new string
 */

char *parse_input(char *input, cmd_t *cmd)
{
	list_t *head, *tmp;
	char *status, *new_input;
	int olen = 0, nlen = 0;

	status = _itoa(cmd->status);
	head = NULL;

	olen = scan_vars(&head, input, status, cmd);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	tmp = head;
	nlen = 0;

	while (tmp != NULL)
	{
		nlen += (tmp->len_val - tmp->var_len);
		tmp = tmp->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_list(&head);

	return (new_input);
}
