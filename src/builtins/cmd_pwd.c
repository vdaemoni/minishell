/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:37:17 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/25 20:18:33 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_pwd(char **args, char **data, char *name)
{
	char	buf[PATH_MAX + 1];
	int		i;

	i = -1;
	while (args[++i])
		NULL;
	if (i > 1)
		ft_putendl("pwd: too many arguments");
	else if (i == 1)
		ft_putendl(getcwd(buf, PATH_MAX));
	return (data);
	(void)name;
}
