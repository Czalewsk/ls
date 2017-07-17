/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_if_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 08:54:34 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/20 09:20:58 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstinsert_if_end(t_list **alst, t_list *new, int (*f)(t_list *,
			t_list *))
{
	t_list		*curs;
	t_list		**prev;

	if (!alst || !new || !f)
		return ;
	prev = &(*alst);
	curs = *prev;
	while (curs && f(curs, new))
	{
		curs = (*prev)->next;
		prev = &(*prev)->next;
	}
	new->next = curs;
	*prev = new;
}
