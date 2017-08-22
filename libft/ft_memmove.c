/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:10:42 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/09 19:56:27 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	l;

	l = len;
	if (len == 0)
		return (dst);
	else if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (l--)
			((UC*)dst)[l] = ((UC*)src)[l];
	return (dst);
}
