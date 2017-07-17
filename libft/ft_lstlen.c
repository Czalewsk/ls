/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:33:29 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/13 14:59:07 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *lst)
{
	t_list	*current;
	size_t	i;

	i = 1;
	if (!lst)
		return (0);
	current = lst;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}
