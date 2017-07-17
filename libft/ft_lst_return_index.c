/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_return_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:21:02 by czalewsk          #+#    #+#             */
/*   Updated: 2017/05/23 13:58:48 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_return_index(t_list *lst, size_t index)
{
	size_t		i;

	i = 0;
	if (!lst)
		return (NULL);
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
