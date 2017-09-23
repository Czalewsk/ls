/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:08:21 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/23 15:48:53 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_sort_time_acc(t_list *prev, t_list *new)
{
	long unsigned		a;
	long unsigned		b;

	a = ((t_ls_info*)(prev->content))->stat.st_atime;
	b = ((t_ls_info*)(new->content))->stat.st_atime;
	if (a < b)
		return (0);
	else if (a > b)
		return (1);
	else
		return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) > 0 ? 0 : 1);
}

int			ls_sort_time_acc_r(t_list *prev, t_list *new)
{
	long unsigned		a;
	long unsigned		b;

	a = ((t_ls_info*)(prev->content))->stat.st_atime;
	b = ((t_ls_info*)(new->content))->stat.st_atime;
	if (a > b)
		return (0);
	else if (a < b)
		return (1);
	else
		return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 0 : 1);
}

int			ls_sort_time_crea(t_list *prev, t_list *new)
{
	long unsigned		a;
	long unsigned		b;

	a = ((t_ls_info*)(prev->content))->stat.st_birthtime;
	b = ((t_ls_info*)(new->content))->stat.st_birthtime;
	if (a < b)
		return (0);
	else if (a > b)
		return (1);
	else
		return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) > 0 ? 0 : 1);
}

int			ls_sort_time_crea_r(t_list *prev, t_list *new)
{
	long unsigned		a;
	long unsigned		b;

	a = ((t_ls_info*)(prev->content))->stat.st_birthtime;
	b = ((t_ls_info*)(new->content))->stat.st_birthtime;
	if (a > b)
		return (0);
	else if (a < b)
		return (1);
	else
		return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 0 : 1);
}

int			ls_sort_name(t_list *prev, t_list *new)
{
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) > 0 ? 0 : 1);
}
