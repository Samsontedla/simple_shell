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

#endif /*HEAD_H*/
