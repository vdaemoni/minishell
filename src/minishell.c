/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:25:15 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/09/05 16:48:31 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_line(void)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

static char	**run_cmd(char **commands, char **data, char *name)
{
	char	**args;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (commands[++j])
	{
		args = ft_strtok(commands[j], " \t\n\r\a\"");
		data = execute(args, data, name);
		free(commands[j]);
		while (args[++i])
			free(args[i]);
		(args) ? free(args) : 0;
		i = -1;
	}
	return (data);
	(void)name;
}

static void	set_dir(char **data, char *name)
{
	char **arg;

	arg = (char **)ft_memalloc(sizeof(char *) * 4);
	arg[0] = NULL;
	arg[1] = ft_strdup("PWD");
	arg[2] = ft_strnew(PATH_MAX);
	arg[3] = 0;
	getcwd(arg[2], PATH_MAX);
	cmd_setenv(arg, data, name);
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

int			minishell(char **data, char *name)
{
	int		i;
	int		status;
	char	*line;
	char	**commands;

	i = 0;
	status = 1;
	cmd_help(NULL, data, NULL);
	while (status)
	{
		ft_putstr("$> ");
		set_dir(data, name);
		line = read_line();
		commands = ft_strtok(line, ";");
		data = run_cmd(commands, data, name);
		status = data ? 1 : 0;
		free(commands);
		free(line);
	}
	ft_putendl("Bye :)");
	return (status);
}
