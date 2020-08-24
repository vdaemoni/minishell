/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:50:57 by jaleman           #+#    #+#             */
/*   Updated: 2020/08/17 18:35:54 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	k;

	i = 0;
	k = c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == k)
			return (char*)(s + i);
		i--;
	}
	return (NULL);
}
