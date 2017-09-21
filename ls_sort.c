/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:20:18 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/21 17:14:07 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_sort_time_mod_r(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_ctime >
			((t_ls_info*)(cur->content))->stat.st_ctime ? 0 : 1);
}

int			ls_sort_time_mod(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_ctime <
			((t_ls_info*)(cur->content))->stat.st_ctime ? 0 : 1);
}

int			ls_sort_name_r(t_list *prev, t_list *new)
{
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) > 0 ? 1 : 0);
}

int			ls_sort_name(t_list *prev, t_list *new)
{
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 1 : 0);
}

int		ls_sort_recursive(t_list *prev, t_list *new)
{
	static int	(*f)(t_list *prev, t_list *cur);

	if (!f)
		f = ls_set_sort(NULL);
	return (((t_ls_info*)(prev->content))->deep <
			((t_ls_info*)(new->content))->deep ? 0 : f(prev, new));
}

void		*ls_set_sort(char (*option)[128])
{
	static int	(*f)(t_list *prev, t_list *cur);

	if (!f && option)
	{
		if ((*option)['t'])
			f = (*option)['r'] ? &ls_sort_time_mod_r : &ls_sort_time_mod;
		else if ((*option)['f'])
			f = (*option)['r'] ? &ls_not_sorted : &ls_not_sorted_r;
		else if ((*option)['S'])
			f = (*option)['r'] ? &ls_sort_size : &ls_sort_size_r;
		else if ((*option)['u'])
			f = (*option)['r'] ? &ls_sort_time_acc : &ls_sort_time_acc_r;
		else if ((*option)['U'])
			f = (*option)['r'] ? &ls_sort_time_crea : &ls_sort_time_crea_r;
		else
			f = (*option)['r'] ? &ls_sort_name_r : &ls_sort_name;
		if ((*option)['R'])
			return (&ls_sort_recursive);
	}
	return (f);
}

