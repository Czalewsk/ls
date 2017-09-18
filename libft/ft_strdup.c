/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:46:33 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/18 17:48:24 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		n;
	char	*s2;

	if (!s1)
		return (NULL);
	n = ft_strlen(s1);
	if (!(s2 = (char*)ft_memalloc((n + 1) * sizeof(*s1))))
		return (NULL);
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (s2 -= n);
}
