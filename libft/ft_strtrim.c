/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:22:55 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/10 14:45:09 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] && (s[start] == 32 || s[start] == 10 || s[start] == 9))
		start++;
	while (s[end - 1] == 32 || s[end - 1] == 10 || s[end - 1] == 9)
		end--;
	if (start > end)
		return (ft_strnew(1));
	else
		return (ft_strsub(s, start, end - start));
}
