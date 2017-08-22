/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:49:17 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/13 11:59:24 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*addr;

	if (!lst || !f)
		return ;
	addr = lst;
	while (addr->next)
	{
		(*f)(addr);
		addr = addr->next;
	}
	(*f)(addr);
}
