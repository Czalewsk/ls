/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:36:57 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/04 10:01:57 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_display_error(t_ls_list *start)
{
	t_list		*cur;

	if (!start->error)
		return ;
	start->print = 1;
	cur = start->error;
	while (cur)
	{
		ft_printf("ls: %s: No such file or directory\n",
				((t_ls_info*)cur->content)->name);
		cur = cur->next;
	}
	ft_lstdel(&start->error, &ls_del_folders);
}
