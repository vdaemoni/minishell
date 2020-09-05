/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:37:39 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/28 16:12:38 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_unsetenv(char **args, char **data, char *name)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	if (!ft_strcmp(args[1], "PWD"))
		ft_putendl("unsetenv: permission denied");
	else if (args[1] && ft_find_env(args[1], data)[0] != 0)
	{
		while (data[++i])
			if (!ft_strncmp(data[i], args[1], len) && data[i][len] == '=')
				break ;
		free(data[i]);
		i--;
		while (data[++i])
			data[i] = data[i + 1];
		data[i] = NULL;
	}
	return (data);
	(void)name;
}
