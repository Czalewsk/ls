/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 02:55:55 by lduval            #+#    #+#             */
/*   Updated: 2017/05/23 14:01:25 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		n;
	int		i;

	i = 0;
	n = ft_strlen(little);
	if (n == 0)
		return ((char*)big);
	while (big)
	{
		while (big[i] == little[i])
			if (++i == n)
				return ((char*)big);
		i = 0;
		big++;
	}
	return (NULL);
}
