/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:50:41 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/27 17:29:23 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "helpers.h"
# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>

int		minishell(char **data, char *name);

char	**execute(char **args, char **data, char *name);

char	**(*blt_func(int i))(char **args, char **data, char *name);
char	*blt_str(int i);

char	**cmd_echo(char **args, char **env, char *name);
char	**cmd_cd(char **args, char **env, char *name);
char	**cmd_setenv(char **args, char **env, char *name);
char	**cmd_unsetenv(char **args, char **env, char *name);
char	**cmd_env(char **args, char **env, char *name);
char	**cmd_exit(char **args, char **env, char *name);
char	**cmd_pwd(char **args, char **env, char *name);
char	**cmd_help(char **args, char **env, char *name);

char	**tricky_1(char **args, char **data, char *name);
char	**tricky_2(char **args, char **data, char *name);
char	**tricky_3(char **args, char **data, char *name);

#endif
