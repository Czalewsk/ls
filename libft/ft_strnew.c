/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:15:36 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/18 17:48:49 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char*)ft_memalloc((sizeof(*str) * (size + 1)))))
		return (NULL);
	while (n < (size + 1))
		str[n++] = '\0';
	return (str);
}
