/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:49:47 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/09/05 17:11:51 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	data_init(char ***data, char **envp)
{
	int i;
	int j;

	i = -1;
	while (envp[++i])
		NULL;
	(*data) = (char **)ft_memalloc(sizeof(char *) * i);
	i = -1;
	while (envp[++i])
	{
		(*data)[i] = (char *)ft_memalloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*data)[i][j] = envp[i][j];
		(*data)[i][j] = 0;
	}
	(*data)[i] = NULL;
	i = -1;
	return ;
}

int			main(int argc, char **argv, char **envp, char **apple)
{
	char **data;

	if (!(envp) || !(*envp) || !(**envp))
		ft_error(1, "./minishell", "Error! null env");
	data_init(&data, envp);
	return (minishell(data, "./minishell"));
	(void)argv;
	(void)argc;
	(void)apple;
}
