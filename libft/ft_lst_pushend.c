/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:10:53 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/14 19:45:37 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushend(t_list **alst, t_list *new)
{
	t_list		*addr;

	if (!new || !alst)
		return ;
	else if (!(*alst))
		*alst = new;
	else
	{
		addr = *alst;
		while (addr->next)
			addr = addr->next;
		addr->next = new;
	}
}
