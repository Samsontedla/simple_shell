#ifndef HEAD_H
#define HEAD_H

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

ssize_t _getline(char **buffer, size_t *n, FILE *stream);
void prompt(void);

#endif /*HEAD_H*/
