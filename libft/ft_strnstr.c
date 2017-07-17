/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:41:47 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/08 18:10:28 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	n = ft_strlen(little);
	if (n == 0)
		return ((char*)big);
	while (*big && cpt < len)
	{
		while (big[i] == little[i] && (cpt + i) < len)
			if (++i == n)
				return ((char*)big);
		i = 0;
		big++;
		cpt++;
	}
	return (NULL);
}
