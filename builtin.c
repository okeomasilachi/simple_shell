#include "main.h"

/**
 * get_cwd - get the current directory of the calling process
 *
 * Return: the abolute path of the directory
*/
char *get_cwd(void)
{
	char path[MAX_PATH];
	char *pth = getcwd(path, sizeof(path));

	if (pth == NULL)
	{
		free(pth);
		return (NULL);
	}
	else
		return (pth);
}

/**
 * get_env - gets the value of an environment variable
 * @name: name of variable
 *
 * Return: the value of the env variable
 */
char *get_env(const char *name)
{
	char **env = environ;

	while (*env != NULL)
	{
		if (_strcmp(*env, name) == 0)
			return (*env + _strlen(name) + 1);

		env++;
	}
	return (NULL);
}

/**
 * set_env - Set a value to an environment variable
 * @name: name of variable
 * @value: value to assign to variable
 * @overwrite: Overwrite a value if set to 0
 *
 * Return: (0) on sucess
 */
int set_env(const char *name, const char *value, int overwrite)
{
	char *old_env, *env_str = malloc(_strlen(name) + _strlen(value) + 3);

	_strcpy(env_str, name);
	_strcat(env_str, "=");
	_strcat(env_str, value);
	if (overwrite)
	{
		return (put_env(env_str));
	}
	else
	{
		old_env = get_env(name);
		if (old_env != NULL)
		{
			free(old_env);
		}
		return (put_env(env_str));
	}
}

/**
 * put_env - change value of an env variable
 * @string: env an value to change
 *
 * Return: (0) on success
 */
int put_env(const char *string)
{
	char **env = environ;
	char *new_env = malloc(_strlen(string) + 1);

	_strcpy(new_env, string);
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


