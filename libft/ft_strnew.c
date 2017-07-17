/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:15:36 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/10 12:30:11 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char*)malloc((sizeof(*str) * (size + 1)))))
		return (NULL);
	while (n < (size + 1))
		str[n++] = '\0';
	return (str);
}
