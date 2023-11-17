#include "shell.h"

/**
 * _myenv - Display the current environment.
 * @info: Structure containing potential arguments. Maintains
 *         a constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Retrieve the value of an environment variable.
 * @info: Structure containing potential arguments. Maintains
 * @name: Environment variable name.
 *
 * Return: The value of the specified environment variable.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments. Maintains
 *         a constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments. Maintains
 *         a constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int q;

	if (info->argc == 1)
	{
		_eputs("few arguments.\n");
		return (1);
	}
	for (q = 1; q < info->argc; q++)
		_unsetenv(info, info->argv[q]);

	return (0);
}

/**
 * populate_env_list - Populate the environment linked list.
 * @info: Structure containing potential arguments. Maintains
 *         a constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t z;

	for (z = 0; environ[z]; z++)
		add_node_end(&node, environ[z], 0);
	info->env = node;
	return (0);
}
