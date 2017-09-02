/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 05:41:12 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/02 14:08:36 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_index(t_list **alst, t_list *new, int index)
{
	t_list		*cur;
	t_list		**prev;
	int			i;

	i = 0;
	if (!alst || index < 0)
		return ;
	prev = alst;
	cur = *alst;
	while (cur && i < index)
	{
		cur = (*prev)->next;
		prev = &(*prev)->next;
		i++;
	}
	*prev = new;
	new->next = cur;
}
