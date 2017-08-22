/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:23:07 by czalewsk          #+#    #+#             */
/*   Updated: 2017/03/09 14:01:17 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdouble(char *str)
{
	int		i;
	int		n;

	i = -1;
	if (!str)
		return (0);
	while (str[++i + 1])
	{
		n = i;
		while (str[++n])
			if (str[n] == str[i])
				return (1);
	}
	return (0);
}
