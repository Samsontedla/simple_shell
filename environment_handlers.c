#include "header.h"

/**
 * create_envi - Creats an array of Enviroment Variables
 * @envi: Array of Enviroment Variable
 */

void create_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_env - Frees the created Enviroment Variable array
 * @env:  Environment variables
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
