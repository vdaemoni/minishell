/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:37:12 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/25 20:25:13 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_help(char **args, char **data, char *name)
{
	int i;

	i = -1;
	ft_putchar('\n');
	ft_putendl("#   # #   # #   # #   # #   # ##### ##### #####");
	ft_putendl("## ## #  ## #   # #  ## # # # #      #  #  #  #");
	ft_putendl("# # # # # # ##### # # # # # # ####   #  #  #  #");
	ft_putendl("#   # ##  # #   # ##  # # # # #      #  #  #  #");
	ft_putendl("#   # #   # #   # #   # ##### ##### #   # #   #\n");
	ft_putendl("Type commands and arguments, and hit enter");
	ft_putendl("The following are built in:");
	while (++i < 8)
		ft_putendl(blt_str(i));
	ft_putendl("\n\nBy vdaemoni\n");
	return (data);
	(void)args;
	(void)name;
}
