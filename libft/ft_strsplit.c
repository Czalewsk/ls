/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:45:34 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/13 14:12:31 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_world(char const *s, char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 1;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			n++;
		else if (i != 0 && s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

static	char	*ft_split_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_strsub(s, 0, i));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s || !c)
		return (NULL);
	if (!(split = (char**)malloc(ft_count_world(s, c) * (sizeof(char**)))))
		return (NULL);
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			split[n++] = ft_split_word(&(s[i]), c);
		else if (i != 0 && s[i] != c && s[i - 1] == c)
			split[n++] = ft_split_word(&(s[i]), c);
		i++;
	}
	split[n] = NULL;
	return (split);
}
