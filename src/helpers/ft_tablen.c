/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:08:37 by jaleman           #+#    #+#             */
/*   Updated: 2020/08/17 18:36:10 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

/*
** Return the number of entries in a table
*/

size_t		ft_tablen(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len += 1;
	return (len);
}
