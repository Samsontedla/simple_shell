#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "head.h"

int _getline(char **buffer, size_t *n, FILE *stream)
{
  read(0,*buffer,*n);
  return(strlen(*buffer));
}
