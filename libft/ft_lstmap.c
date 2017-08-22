/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:00:59 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/16 15:32:14 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		**start_lst;
	t_list		*new;
	t_list		*current;

	if (!lst || !f)
		return (NULL);
	if (!(new = (t_list*)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(start_lst = (t_list**)ft_memalloc(sizeof(**start_lst))))
		return (NULL);
	current = lst;
	while (current->next)
	{
		new = (*f)(current);
		ft_lst_pushend(start_lst, ft_lstnew(new->content, new->content_size));
		current = current->next;
	}
	new = (*f)(current);
	ft_lst_pushend(start_lst, ft_lstnew(new->content, new->content_size));
	free(current);
	return (*start_lst);
}
