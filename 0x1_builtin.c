#include "shell.h"

/**
 * get_cwd - get current working directory
 *
 * Return: current working directory
*/
char *get_cwd(void)
{
	char path_size[MAX_PATH];
	char *path;

	path = getcwd(path_size, sizeof(path_size));

	if (path == NULL)
	{
		free(path);
		return (NULL);
	}
	else
	{
		return (path);
	}
}

/**
 * _getenv - get environment variable
 * @env_name: environment variable name
 *
 * Return: environment variable
*/
char *_getenv(const char *env_name)
{
	char **env;

	env = environ;

	while (*env != NULL)
	{
		if (_strcmp(*env, env_name) == 0)
			return (*env + _strlen(env_name) + 1);
		env++;
	}
	return (NULL);
}

/**
 * _setenv - set environment variable
 * @name: environment variable name
 * @value: environment variable value
 * @overwrite: overwrite environment variable
 *
 * Return: 0 on success, -1 on failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	char *old_env, *env_str;

	env_str = malloc(_strlen(name) + _strlen(value) + 3);
	_strcpy(env_str, name);
	_strcat(env_str, "=");
	_strcat(env_str, value);
	if (overwrite)
	{
		return (_putenv(env_str));
	}
	else
	{
		old_env = _getenv(name);
		if (old_env != NULL)
			free(old_env);
		return (_putenv(env_str));
	}
}

/**
 * _putenv - put environment variable
 * @str: environment variable
 *
 * Return: 0 on success, -1 on failure
*/
int _putenv(const char *str)
{
	char **env = environ;
	char *new_env;

	new_env = malloc(_strlen(str) + 1);

	_strcpy(new_env, str);
	while (*env != NULL)
	{
		if (_strcmp(*env, new_env) == 0)
		{
			free(new_env);
			return (0);
		}
		env++;
	}
	*env = new_env;
	return (0);
}
