/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:37:21 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/27 17:32:16 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**replace(char **args, char **data)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	while (data[++i])
	{
		if (!ft_strncmp(data[i], args[1], len) && data[i][len] == '=')
			break ;
	}
	ft_strclr(data[i]);
	ft_strcat(data[i], args[1]);
	ft_strcat(data[i], "=");
	ft_strcat(data[i], args[2]);
	return (data);
}

static char	**create_new(char **args, char **data)
{
	char	***e;
	char	**envp;
	int		i;

	i = -1;
	e = &data;
	while ((*e)[++i])
		NULL;
	envp = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = -1;
	while ((*e)[++i])
		envp[i] = ft_strdup((*e)[i]);
	ft_tabfree(data);
	envp[i] = (char *)ft_memalloc(PATH_MAX + 1);
	ft_strncat(envp[i], args[1], ft_strlen(args[1]));
	ft_strncat(envp[i], "=", 1);
	ft_strncat(envp[i], args[2], ft_strlen(args[2]));
	e = &envp;
	return (*e);
}

static void	free_arg(char **arg)
{
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

static char	**one_arg(char **args, char **data, char *name)
{
	int		i;
	int		j;
	char	**arg;

	i = (args[1][0] == '"');
	j = 0;
	arg = (char **)ft_memalloc(sizeof(char *) * 3);
	arg[0] = NULL;
	arg[1] = ft_strnew(sizeof(args[1]));
	arg[2] = ft_strnew(sizeof(args[1]));
	while (args[1][j] != '=' && args[1][i])
		arg[1][j++] = args[1][i++];
	if (!args[1][i])
	{
		free_arg(arg);
		return (data);
	}
	if (args[1][i] == '=' && args[1][i + 1] == '"')
		i++;
	j = 0;
	while (args[1][++i] != '"' && args[1][i])
		arg[2][j++] = args[1][i];
	data = cmd_setenv(arg, data, name);
	free_arg(arg);
	return (data);
}

char		**cmd_setenv(char **args, char **data, char *name)
{
	if (!args[1])
		return (data);
	if (!args[2])
		return (one_arg(args, data, name));
	if (args[1] && !ft_strcmp(args[2], "=") && args[3])
		return (tricky_3(args, data, name));
	else if (args[1] && args[2][0] == '=')
		return (tricky_2(args, data, name));
	else if (args[1][ft_strlen(args[1]) - 1] == '=' && args[2])
		return (tricky_1(args, data, name));
	if (ft_find_env(args[1], data)[0] != 0)
		return (replace(args, data));
	return (create_new(args, data));
	(void)name;
}
