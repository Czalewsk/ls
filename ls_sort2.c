/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:28:55 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/23 15:01:33 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_not_sorted(t_list *prev, t_list *new)
{
	(void)prev;
	(void)new;
	return (1);
}

int			ls_not_sorted_r(t_list *prev, t_list *new)
{
	(void)prev;
	(void)new;
	return (0);
}

int			ls_sort_size(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_size <
			((t_ls_info*)(cur->content))->stat.st_size ? 0 : 1);
}

int			ls_sort_size_r(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_size >
			((t_ls_info*)(cur->content))->stat.st_size ? 0 : 1);
}

int			ls_sort_time_mod_r(t_list *prev, t_list *new)
{
	unsigned long	a;
	unsigned long	b;

	a = ((t_ls_info*)(prev->content))->stat.st_mtime;
	b = ((t_ls_info*)(new->content))->stat.st_mtime;
	if (a > b)
		return (0);
	else if (a < b)
		return (1);
	else
		return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 0 : 1);
}
