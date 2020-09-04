/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:36:34 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/09/04 17:54:02 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msg(char *str, char *path)
{
	ft_putstr(str);
	ft_putendl(path);
}

static void	set_dir(char **data, char *name)
{
	char **arg;

	arg = (char **)ft_memalloc(sizeof(char *) * 4);
	arg[0] = NULL;
	arg[1] = ft_strdup("OLDPWD");
	arg[2] = ft_strnew(PATH_MAX);
	arg[3] = 0;
	getcwd(arg[2], PATH_MAX);
	cmd_setenv(arg, data, name);
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

static void	access_dir(char **data, char *path)
{
	struct stat stst;

	if (!(access(path, F_OK) == -1))
	{
		lstat(path, &stst);
		if (S_ISDIR(stst.st_mode) && !(stst.st_mode & S_IXUSR))
			msg("cd: permission denied: ", path);
		else if (!S_ISDIR(stst.st_mode))
			msg("cd: not a directory: ", path);
		else
		{
			set_dir(data, "OLDPWD");
			chdir(path);
		}
	}
	else
		msg("cd: no such file or directory: ", path);
	return ;
}

static char	*ft_dolla_sign(char *p, char **args, char **data)
{
	int		i;
	int		j;
	char	*help;

	i = 0;
	j = 0;
	while (args[0][i] && args[0][i] != '/')
		i++;
	help = ft_strnew(i);
	ft_strncpy(help, args[0], i);
	if (ft_find_env(help, data))
	{
		ft_strcat(p, ft_find_env(help, data));
		if (args[0][i] == '/')
			ft_strcat(p, ft_strchr(args[0], '/'));
	}
	free(help);
	return (p);
}

char		**cmd_cd(char **args, char **data, char *name)
{
	char	*p;
	int		count;

	count = ft_tablen(args);
	p = ft_strnew(PATH_MAX);
	if (count < 3)
	{
		(args)++;
		if (!*args || !ft_strcmp(*args, "~") || !ft_strncmp(*args, "~/", 2))
			ft_strcat(p, ft_find_env("~", data));
		if (*args && !ft_strncmp(*args, "~/", 2) && ft_strlen(*args) > 2)
			ft_strncat(p, (*args + 1), ft_strlen(*args));
		else if (*args && !ft_strcmp(*args, "-"))
			ft_putendl(ft_strcat(p, ft_find_env("$OLDPWD", data)));
		else if (*args && *(args)[0] == '$' && ft_strlen(*args) > 1)
			ft_dolla_sign(p, args, data);
		else if (*args && (*args)[0] != '~' && (*args)[0] != '-')
			ft_strncat(p, *args, PATH_MAX);
		access_dir(data, p);
	}
	else
		ft_putendl("cd: too many arguments");
	free(p);
	return (data);
	(void)name;
}
