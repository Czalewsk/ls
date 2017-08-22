/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:27:08 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/13 14:11:06 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	char			*str;

	l = 0;
	if (s == NULL || f == NULL || !(str = ft_strdup(s)))
		return (NULL);
	while (str[l])
	{
		str[l] = (*f)(l, str[l]);
		l++;
	}
	return (str);
}
