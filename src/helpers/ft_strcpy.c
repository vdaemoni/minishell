/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:28 by jaleman           #+#    #+#             */
/*   Updated: 2020/08/17 18:32:58 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

/*
** Copy the string src to dst (including the terminating `\0' character).
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
