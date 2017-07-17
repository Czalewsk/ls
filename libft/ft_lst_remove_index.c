/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:41:12 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/13 10:57:54 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_index(t_list **alst, int index,
		void (*del)(void *, size_t))
{
	t_list		*cur;
	t_list		**prev;
	int			i;

	i = 0;
	if (!alst || index < 0)
		return ;
	prev = &(*alst);
	cur = *prev;
	while (cur->next && i < index)
	{
		cur = (*prev)->next;
		prev = &(*prev)->next;
		i++;
	}
	*prev = cur->next;
	cur->next = NULL;
	if (del)
		del(cur->content, cur->content_size);
	free(cur);
	cur = *prev;
}
