/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:23:16 by jaleman           #+#    #+#             */
/*   Updated: 2020/08/17 18:32:27 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char*)b;
	while (len-- > 0)
	{
		*str++ = (unsigned char)c;
	}
	return (b);
}
