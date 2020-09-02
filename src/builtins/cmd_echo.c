/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:36:52 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/30 15:01:34 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_eval(char **data, char *arg)
{
	int		i;
	char	*eval;

	i = 0;
	eval = NULL;
	while (data && data[++i])
		if (!ft_strncmp(data[i], (arg + 1), ft_strlen(arg) - 1))
			eval = ft_strrchr(data[i], '=') + 1;
	return (eval);
}

static char	*echo_arg(char **data, char *arg, int last)
{
	char *s;

	if ((s = ((arg && arg[0] == '$') ? get_eval(data, arg) : arg)))
		ft_putstr(s);
	ft_putchar(!last ? ' ' : '\n');
	return (s);
}

char		**cmd_echo(char **args, char **data, char *name)
{
	int i;

	i = 0;
	if (*args && !args[1])
		ft_putchar('\n');
	else if (*args && args[1])
		while (args[++i])
			echo_arg(data, args[i], (args[i + 1] ? 0 : 1));
	return (data);
	(void)name;
}
