/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:06:41 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/09/02 18:45:49 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_ps(char *ex, char **args, char **data, char *name)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(ex, args, data) == -1 \
			? ft_error(1, name, "permission denied") : 0;
	else if (pid < 0)
		ft_error(1, name, "failed to fork");
	else
		wait(&pid);
	return (1);
}

static void	check_error(char *p, char *arg, char *name)
{
	int i;
	int slash;

	i = -1;
	slash = 0;
	while (arg[++i])
		if (arg[i] == '/')
			slash += 1;
	if (slash > 0 && !p)
	{
		ft_putstr(name);
		ft_putendl(": no such file or directory");
	}
	else if (!p)
	{
		ft_putstr(name);
		ft_putendl(": command not found");
	}
	return ;
}

static void	find_cmd(char **args, char **data, char *name)
{
	char	**p;
	char	*path;
	int		i;

	i = -1;
	p = ft_strtok(ft_find_env("$PATH", data), ":");
	path = ft_strnew(PATH_MAX);
	while (p[++i])
	{
		ft_strclr(path);
		ft_strcat(path, p[i]);
		(args[0][0] != '/') ? ft_strcat(path, "/") : 0;
		ft_strcat(path, args[0]);
		if (access(path, F_OK) != -1)
		{
			execute_ps(path, args, data, name);
			break ;
		}
	}
	check_error(p[i], args[0], name);
	i = -1;
	while (p[++i])
		free(p[i]);
	free(path);
	free(p);
}

char		**execute(char **args, char **data, char *name)
{
	int i;

	i = -1;
	if (!args || !*args || !**args)
		return (data);
	while (++i < 8)
		if (!ft_strcmp(args[0], blt_str(i)))
			return ((*blt_func(i))(args, data, name));
	if (access(args[0], F_OK) != -1)
		execute_ps(args[0], args, data, name);
	else
		find_cmd(args, data, name);
	return (data);
}
