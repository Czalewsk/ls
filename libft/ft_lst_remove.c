/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:30:45 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 15:04:31 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove(t_list **alst, t_list *dl, void (*del)(void *, size_t))
{
	t_list		*cur;
	t_list		**prev;

	prev = &(*alst);
	cur = *prev;
	while (cur)
	{
		if (cur == dl)
		{
			*prev = cur->next;
			cur->next = NULL;
			del(cur->content, cur->content_size);
			free(cur);
			cur = *prev;
		}
		else
		{
			cur = (*prev)->next;
			prev = &(*prev)->next;
		}
	}
}
