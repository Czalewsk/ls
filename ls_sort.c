/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:20:18 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/16 16:36:44 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			sort_time_modified_r(t_list *prev, t_list *cur)
{
	if (((t_ls_info*)(prev->content))->deep <
			((t_ls_info*)(cur->content))->deep)
		return (0);
	return (((t_ls_info*)(prev->content))->stat.st_ctime >
			((t_ls_info*)(cur->content))->stat.st_ctime ? 0 : 1);
}

static int			sort_time_modified(t_list *prev, t_list *cur)
{
	if (((t_ls_info*)(prev->content))->deep <
			((t_ls_info*)(cur->content))->deep)
		return (0);
	return (((t_ls_info*)(prev->content))->stat.st_ctime <
			((t_ls_info*)(cur->content))->stat.st_ctime ? 0 : 1);
}

static int			sort_name_r(t_list *prev, t_list *new)
{
	if (((t_ls_info*)(prev->content))->deep <
			((t_ls_info*)(new->content))->deep)
		return (0);
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) > 0 ? 1 : 0);
}

int					ls_sort_name(t_list *prev, t_list *new)
{
	if (((t_ls_info*)(prev->content))->deep <
			((t_ls_info*)(new->content))->deep)
		return (0);
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 1 : 0);
}

void				*ls_set_sort(char (*option)[128])
{
	static int	(*f)(t_list *prev, t_list *cur);

	if (!f && option)
	{
		if ((*option)['t'])
			f = (*option)['r'] ? &sort_time_modified_r : &sort_time_modified;
		else
			f = (*option)['r'] ? &sort_name_r : &ls_sort_name;
	}
	return (f);
}
