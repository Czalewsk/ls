/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:28:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/04/30 11:08:12 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && (*alst))
	{
		if ((*alst)->next)
			ft_lstdel(&((*alst)->next), (*del));
		ft_lstdelone(alst, (*del));
	}
}
