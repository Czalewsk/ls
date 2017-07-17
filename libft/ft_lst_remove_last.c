/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:51:44 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/10 05:34:40 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_last(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*cur;
	t_list		**prev;

	if (!alst)
		return ;
	prev = &(*alst);
	cur = *prev;
	while (cur->next)
	{
		cur = (*prev)->next;
		prev = &(*prev)->next;
	}
	*prev = cur->next;
	cur->next = NULL;
	del(cur->content, cur->content_size);
	free(cur);
	cur = *prev;
}
