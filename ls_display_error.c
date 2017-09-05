/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:36:57 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/05 18:21:35 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_display_error(t_ls_list *start)
{
	t_list		*cur;
	t_ls_info	*file;

	if (!start->error)
		return ;
	start->print = 1;
	cur = start->error;
	while (cur)
	{
		file = cur->content;
		if (file->err == 20)
			ft_printf("ls: %s: Not a directory\n", file->name);
		else
			ft_printf("ls: %s: No such file or directory\n", file->name);
		cur = cur->next;
	}
	ft_lstdel(&start->error, &ls_del_folders);
}
