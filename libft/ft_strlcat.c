/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:29:32 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/09 19:33:24 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;

	l = ft_strlen(dst);
	if (size <= (l + 1))
		return (ft_strlen(src) + size);
	ft_strncat(dst, src, (size - l - 1));
	return (l + ft_strlen(src));
}
