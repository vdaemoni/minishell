/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by jaleman           #+#    #+#             */
/*   Updated: 2020/08/17 18:32:24 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	ft_error(int err, char *exe, char *msg)
{
	ft_putstr(exe);
	ft_putchar(':');
	ft_putendl(msg);
	return (exit(err));
}
