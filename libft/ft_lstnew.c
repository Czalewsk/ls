/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:04:34 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/13 14:09:05 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*addr;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		addr = ft_memalloc(content_size);
		new->content = ft_memmove(addr, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
