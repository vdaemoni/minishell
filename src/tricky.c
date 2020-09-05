/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricky.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:12:54 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/27 17:35:12 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_arg(char **arg)
{
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

char		**tricky_1(char **args, char **data, char *name)
{
	char	**arg;
	int		i;
	int		j;

	i = -1;
	j = -1;
	arg = (char **)ft_memalloc(sizeof(char *) * 3);
	arg[0] = NULL;
	arg[1] = ft_strnew(ft_strlen(args[1]) - 1);
	while (args[1][++i] != '=')
		arg[1][++j] = args[1][i];
	arg[2] = ft_strdup(args[2]);
	data = cmd_setenv(arg, data, name);
	free_arg(arg);
	return (data);
}

char		**tricky_2(char **args, char **data, char *name)
{
	char	**arg;
	int		i;
	int		j;

	i = 0;
	j = -1;
	arg = (char **)ft_memalloc(sizeof(char *) * 3);
	arg[0] = NULL;
	arg[1] = ft_strdup(args[1]);
	arg[2] = ft_strnew(ft_strlen(args[2]) - 1);
	while (args[2][++i])
		arg[2][++j] = args[2][i];
	data = cmd_setenv(arg, data, name);
	free_arg(arg);
	return (data);
}

char		**tricky_3(char **args, char **data, char *name)
{
	char	**arg;

	arg = (char **)ft_memalloc(sizeof(char *) * 3);
	arg[0] = NULL;
	arg[1] = ft_strdup(args[1]);
	arg[2] = ft_strdup(args[3]);
	data = cmd_setenv(arg, data, name);
	free_arg(arg);
	return (data);
}
