/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:36:55 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/14 19:46:51 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_split_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_strsub(s, 0, i));
}

t_list			**ft_strsplit_lst(char const *s, char c)
{
	t_list		**start;
	size_t		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(start = (t_list**)malloc(sizeof(t_list**))))
		return (NULL);
	*start = NULL;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			ft_lst_pushend(start, ft_lst_newstr(ft_split_word(&(s[i]), c)));
		else if (i != 0 && s[i] != c && s[i - 1] == c)
			ft_lst_pushend(start, ft_lst_newstr(ft_split_word(&(s[i]), c)));
		i++;
	}
	return (start);
}
