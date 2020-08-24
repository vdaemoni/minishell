/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:36:29 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/24 15:41:29 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*blt_str(int i)
{
	char	*blt_str[10];

	blt_str[0] = "cd";
	blt_str[1] = "echo";
	blt_str[2] = "exit";
	blt_str[3] = "env";
	blt_str[4] = "setenv";
	blt_str[5] = "unsetenv";
	blt_str[6] = "help";
	blt_str[7] = "pwd";
	blt_str[8] = "squirtle";
	blt_str[9] = NULL;
	return (blt_str[i]);
}

char	**(*blt_func(int i))(char **args, char **data, char *name)
{
	char	**(*blt_func[9])(char **args, char **env, char *name);

	blt_func[0] = &cmd_cd;
	blt_func[1] = &cmd_echo;
	blt_func[2] = &cmd_exit;
	blt_func[3] = &cmd_env;
	blt_func[4] = &cmd_setenv;
	blt_func[5] = &cmd_unsetenv;
	blt_func[6] = &cmd_help;
	blt_func[7] = &cmd_pwd;
	blt_func[8] = &cmd_squirtle;
	return (blt_func[i]);
}
