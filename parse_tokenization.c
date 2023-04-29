#include "simple_shell.h"

/**
 * evar_check - checks if it is an env variable
 *
 * @head: reps the head
 * @input: reps the input
 * @cmd: struct
 * Return: ....
 */
void evar_check(list_t **head, char *input, cmd_t *cmd)
{
	int i, j, k, lval;
	char **_envr;

	_envr = cmd->envar;

	i = 0;

	while (_envr[i])
	{
		j = 0;
		while (_envr[i][j])
		{
			if (_envr[i][j] == '=')
			{
				lval = _strlen(_envr[i] + j + 1);
				add_node_end(head, k, _envr[i] + j + 1, lval);
				return;
			}

			if (input[k] == _envr[i][j])
			{
				k++;
				j++;
			}
			else
			{
				break;
			}
		}
		i++;
	}

	k = 0;

	while (input[k] && !(input[k] == ' ' || input[k] == '\t' || input[k] == ';' || input[k] == '\n'))
	{
		k++;
	}

	add_node_end(head, k, NULL, 0);
}





/**
 * scan_vars - variable is $$ or $?
 *
 * @h: head of the linked list
 * @input: prompt
 * @status: status of the Shell
 * @cmd: the data structure
 * Return: ...
 */
int scan_vars(list_t **h, char *input, char *status, cmd_t *cmd)
{
	int j = 0;;
	int i = 0;
	int stlen;
	int pid_len;

	stlen = _strlen(status);

	pid_len = _strlen(cmd->pid);

	do {
		if (input[i] == '$')
		{
			switch (input[j])
			{
				case '?':
					add_node_end(h, 2, status, stlen);
					i++;
					break;
				case '$':
					add_node_end(h, 2, cmd->pid, pid_len);
					i++;
					break;
				case ' ':
				case '\n':
				case '\0':
				case '\t':
				case ';':
					add_node_end(h, 0, NULL, 0);
					break;
				default:
					evar_check(h, input + 1, cmd);
					break;
			}
		}
		i++;
		j++;
	} while (input[i]);

	return (i);
}

/**
 * replaced_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(list_t **head, char *input, char *new_input, int nlen)
{
	list_t *indx;
	int i, j, k;

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
 * parse_input - replaces string into variables
 *
 * @input: input string
 * @cmd: data structure
 * Return: the new string
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
