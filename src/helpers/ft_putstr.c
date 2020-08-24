/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:23:16 by jaleman           #+#    #+#             */
/*   Updated: 2020/08/17 18:32:34 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int		ft_putstr(char *str)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (str[++i])
		ret += ft_putchar(str[i]);
	return (ret);
}
