#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fcntl.h>

#define DELIMITERS " \t\n"

extern char **environ;

/*string funcs*/
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int numlen(int n);
char *int_to_string(int number);




/*cus shell funcs*/
char *read_command(void);
char **tokenize(char *line);
int execute_command(char **command, char **av, int index);
char *get_env(char *var);
char *get_path(char *command);


/*util funcs*/
void free2dar(char **array);
void print_error(char *sh_name, char *command, int index);



#endif
