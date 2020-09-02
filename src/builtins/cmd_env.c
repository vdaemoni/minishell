/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:36:59 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/25 20:24:56 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_env(char **args, char **data, char *name)
{
	int i;

	i = -1;
	while (data[++i])
		ft_putendl(data[i]);
	return (data);
	(void)args;
	(void)name;
}
