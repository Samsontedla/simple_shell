#ifndef HEAD_H
#define HEAD_H

/***** MACROS *****/

#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define BUFSIZE 1024
#define DELIMITER " \t\r\n\a"

/*** STANDARD LIBRARIES ***/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/******** STRING HANDLER FUNCTIONS **********/

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);


ssize_t _getline(char **buffer, size_t *n, FILE *stream);
void prompt(void);

/****** FILE ARGUMENT HANDLER FUNCTIONS ******/

void read_file(char *file, char **argv);
void treat_file(char *line, int count, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/****** PARSED ARGUMENT HANDLER FUNCTIONS *****/

int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *input, int c, char **argv);
oid signal_to_handel(int sig);

/****** BUILT-IN COMMANDS STRUCT *****/

/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Custom function that has similar functionality as built-in
 */

typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int er);
} built_in;

#endif /*HEAD_H*/
