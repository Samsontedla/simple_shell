#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "head.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{
	buffer = malloc(sizeof(char) * (*n));
	
	read(fileno(stream), *buffer, *n);
	return(strlen(*buffer));
}
