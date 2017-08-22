/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_newstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:11:37 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 10:36:37 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_newstr(char *str)
{
	t_list		*new;

	if (!str)
		return (NULL);
	new = ft_lstnew(str, ft_strlen(str) + 1);
	new->next = NULL;
	return (new);
}
