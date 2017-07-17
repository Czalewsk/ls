/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:24:56 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/16 11:21:21 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_cpy(t_list *lst, int r)
{
	t_list	*curs;
	t_list	*new;

	new = NULL;
	curs = lst;
	while (curs)
	{
		if (!r)
			ft_lst_pushend(&new, ft_lstnew(curs->content, curs->content_size));
		else
			ft_lstadd(&new, ft_lstnew(curs->content, curs->content_size));
		curs = curs->next;
	}
	return (new);
}
