/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:06:08 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/09 20:25:58 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	l;

	l = 0;
	if (s == NULL || f == NULL || !(str = ft_strdup(s)))
		return (NULL);
	while (str[l])
	{
		str[l] = (*f)(str[l]);
		l++;
	}
	return (str);
}
