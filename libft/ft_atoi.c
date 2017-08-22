/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:31:56 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 10:36:16 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int signe;

	signe = 1;
	n = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45)
	{
		signe = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
		n = (*str++ - 48) + n * 10;
	n *= signe;
	return (n);
}
