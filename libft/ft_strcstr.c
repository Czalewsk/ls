/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:01:35 by czalewsk          #+#    #+#             */
/*   Updated: 2017/03/09 12:06:22 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_strcstr(char *str, char *chaine)
{
	int		i;
	int		n;

	i = -1;
	if (!str || !chaine)
		return (0);
	while (str[++i])
	{
		n = -1;
		while (chaine[++n])
			if (str[i] == chaine[n])
				return (str[i]);
	}
	return (0);
}
