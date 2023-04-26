1. Simple shell 0.1
Write a UNIX command line interpreter.
Usage: simple_shell

2. Simple shell 0.2
Simple shell 0.1 +
Handle command lines with arguments

3. Simple shell 0.3
Simple shell 0.2 +
Handle the PATH
fork must not be called if the command doesn’t exist

4. Simple shell 0.4
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

5. Simple shell 1.0
Simple shell 0.4 +

Implement the env built-in, that prints the current environment

6. Simple shell 0.1.1
Simple shell 0.1 +

Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
You don’t have to:

be able to move the curso

7. Simple shell 0.2.1
Simple shell 0.2 +

You are not allowed to use strtok


8. Simple shell 0.4.1
Simple shell 0.4 +

handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell

9. setenv, unsetenv
Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure

10. cd
Simple shell 1.0 +

Implement the builtin command cd:

Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
man chdir, man getcwd

11. ;
Simple shell 1.0 +

Handle the commands separator ;
12. && and ||
Simple shell 1.0 +

Handle the && and || shell logical operators

13. alias
Simple shell 1.0 +

14. Variables
Simple shell 1.0 +

Handle variables replacement
Handle the $? variable
Handle the $$ variable


15. Comments
Simple shell 1.0 +

Handle comments (#)

16. File as input
Simple shell 1.0 +
