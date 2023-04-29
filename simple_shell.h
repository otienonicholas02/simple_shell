#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>
#include <signal.h>

#define EXEC 1
#define MAXARGS 128
#define DELIM " \t\n\r\a"

extern char **environ;

/**
 * struct cmd_t - reps shell env vars
 * @mode: represents mode of execution
 * @args: represents args
 * @ready: determines if shell is ready
 * @status: the status command
 * @av: the argvector
 * @counter: num of loops.
 * @pid: pid of the command
 * @input: prompt.
 * @envar:env  variables.
 *
 * Description: the struct.
 */
typedef struct cmd_t
{
	int mode;
	char *input;
	char **args;
	int ready;
	int status;
	char **envar;
	int counter;
	char **av;
	char *pid;
} cmd_t;

void open_console(void);
void init_cmd(cmd_t *cmd, char **av);
void prompt(int status);
void t_error(char *s);
int _fork(void);
void setcmd(char *buf, cmd_t *cmd);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
char *_readwrite(int status, int *is_eof);
void runcmd(char *dir, char **input, cmd_t *cmd);
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream);
char *_strtok(char *strn, const char *delim);
void handl_sigint(int sig);
char *handl_comment(char *input);
int execution(cmd_t *cmd);
void _loop(cmd_t *cmd);
int cmd_exec(cmd_t *cmd);
int check_dir_access(char *dir, cmd_t *cmd);
int apply_seperators(cmd_t *cmd, char *input);


char *_which(char *cmd, char **_environ);
int _env(cmd_t *cmd);
char *_getenv(const char *name, char **_environ);


/**
 * struct builtins - struct
 * @name: reps the name
 * @f: represents function
 *
 * Description: struct function
 */
typedef struct builtins
{
	char *name;
	int (*f)(cmd_t *cmd);
} built_t;

int parse_builtins(cmd_t *cmd);
int exit_sh(cmd_t *cmd);
int c_dir(cmd_t *cmd);
int _setenv(cmd_t *cmd);
void set_env(char *name, char *value, cmd_t *cmd);
int _unsetenv(cmd_t *cmd);
int get_help(cmd_t *cmd);

int cd_path(char *dir, cmd_t *cmd);
int cd_parent(cmd_t *cmd);
int cd_curr(cmd_t *cmd);
int cd_back(cmd_t *cmd);
int cd_home(cmd_t *cmd);


/**
 * struct list_s - linked list
 * @var_len: ...
 * @val: ...
 * @len_val:...
 * @next: ....
 * Description: store variables
 */
typedef struct list_s
{
	int var_len;
	char *val;
	int len_val;
	struct list_s *next;
} list_t;

/**
 * struct sep_s - ...
 * @sep: serperator
 * @next: pointer to node
 * Description: linked list holding the seperators
 */
typedef struct sep_s
{
	char sep;
	struct sep_s *next;
} sep_t;

/**
 * struct line_s - linked list
 * @line: line
 * @next: ....
 * Description: command lines
 */
typedef struct line_s
{
	char *line;
	struct line_s *next;
} line_t;


int _isdigit(const char *str);
char **get_toks(char *args, char *delimiter);
void str_reverse(char *s);
char *_strdup(char *str);
int _strcmp(char *str_a, char *str_b);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
int is_cdir(char *path, int *i);
int (*get_builtin(char *input))(cmd_t *);
char *parse_input(char *input, cmd_t *cmd);
char *replaced_input(list_t **head, char *input, char *new_input, int nlen);
int scan_vars(list_t **h, char *input, char *status, cmd_t *cmd);
void evar_check(list_t **head, char *input, cmd_t *cmd);
int get_len(int n);
char *_itoa(int n);
char *copy_info(char *name, char *value);


void free_grid(char **grid, int height);
void free_cmd(cmd_t *cmd);


sep_t *add_sep_node_end(sep_t **head, char sep);
void free_sep_list(sep_t **head);
line_t *add_line_node_end(line_t **head, char *line);
void free_line_list(line_t **head);

list_t *add_node_end(list_t **head, int var_len, char *val, int len_val);
void free_list(list_t **head);


void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);


void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);


int get_help(cmd_t *cmd);

/* prototypes */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(cmd_t *cmd, char *input, int i, int bool);
int check_syntax_error(cmd_t *cmd, char *input);


#endif
