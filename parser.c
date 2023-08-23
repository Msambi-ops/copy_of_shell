#include "shell.h"

/**
 * is_cmd - it ascertain if the file is executable command
 * @info: structure info
 * @path: file path
 *
 * Return: returns 1 on succesfull execution
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st. st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - it corresponds characters
 * @pathstr: is string path
 * @start: index that starts
 * @stop: it stops indes
 *
 * Return: it points to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - it will find the cmd on the path string
 * @info: struct information
 * @pathstr: string path
 * @cmd: cmd to find
 *
 * Return: is the complete path of cmd if found or else NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
