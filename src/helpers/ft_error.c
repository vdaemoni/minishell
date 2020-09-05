/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:03:01 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/09/02 18:45:44 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	ft_error(int err, char *exe, char *msg)
{
	ft_putstr(exe);
	ft_putchar(':');
	ft_putchar(' ');
	ft_putendl(msg);
	return (exit(err));
}
