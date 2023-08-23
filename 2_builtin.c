#include "shell.h"

/**
* _myexit-leaves the shell
* @info:struc holds crucial arguments.Restores constant function protoype
* Return: leaves with a instructed leave status
* (0) if info. argv[0] != "exit"
*/
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* if there's an exit ars */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "illegal number:");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
* _mycd- shifts the process of the current directory
* @info: holds potential arguments.Restores constant functon prototype
* Return: Always 0
*/
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* what could it be */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") ==	0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dir = _getenv(info, "PWD=")) ? dir : "/");

	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
* _myhelp - shifts current directory of the procedure
* @info: is a function holding crucial arguments.Restore const func prototype
* Return: Ever 0
*/
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call work. Function is not implemented yet \n");
	if (0)
		_puts(*arg_array);
	return (0);

}
