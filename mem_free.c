#include "shell.h"

/**
 * free_all - free's all dynamically allocated memory
 * @oki: struct of type okeoma
 *
 * Return: void
*/
void free_all(okeoma *oki)
{
	if (oki->pos != NULL)
		free_recursive(oki->pos);
	free_list(oki->head);

	var_free(oki);
	if (oki->cmd)
		free(oki->cmd);
	if (oki->ok)
		free(oki->ok);
	if (oki->old)
		free(oki->old);
	if (oki->tok)
		free(oki->tok);
	if (oki->path)
		free(oki->path);

	free(oki);
}

/**
 * fr__ - free count number of dynamically allocated memory
 * @count: number of memory to free
 *
 * Return: void
*/
void fr__(size_t count, ...)
{
	void *ptr;
	va_list args;
	size_t i;

	if (count <= 0)
	{
		p(STE, "Invalid number of arguments for fr__\n");
		return;
	}
	va_start(args, count);
	for (i = 0; i < count; i++)
	{
		ptr = va_arg(args, void *);

		if (ptr != NULL)
			free(ptr);
		else
			continue;
	}
	va_end(args);
}
