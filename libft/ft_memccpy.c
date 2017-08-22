/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:49:44 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/08 21:30:41 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	size_t l;

	l = 0;
	i = 0;
	while (i < n)
	{
		((UC*)dst)[i] = ((UC*)src)[l];
		if ((UC)c == ((UC*)src)[l])
			return (dst + i + 1);
		i++;
		l++;
	}
	return (NULL);
}
