/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:20:18 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/23 14:32:27 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*ls_choose_sort(char (*option)[128])
{
	int			l;
	int			i;
	static int	(*f)(t_list *prev, t_list *cur);
	const char	sort[] = "tfSuU";
	const void	*adress[][2] = {{&ls_sort_time_mod, &ls_sort_time_mod_r},
		{&ls_not_sorted, &ls_not_sorted_r}, {&ls_sort_size, ls_sort_size_r},
		{&ls_sort_time_acc, ls_sort_time_acc_r}, {&ls_sort_time_crea,
		&ls_sort_time_crea_r}, {&ls_sort_name, &ls_sort_name_r}};

	if (!f)
	{
		i = -1;
		l = ft_strlen(sort);
		while (++i < l)
			if ((*option)[(int)sort[i]])
				break ;
		f = adress[i][(int)(*option)['r']];
	}
	return (f);
}

int			ls_sort_time_mod(t_list *prev, t_list *new)
{
	unsigned long	a;
	unsigned long	b;

	a = ((t_ls_info*)(prev->content))->stat.st_mtime;
	b = ((t_ls_info*)(new->content))->stat.st_mtime;
	if (a < b)
		return (0);
	else if (a > b)
		return (1);
	else
		return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) > 0 ? 0 : 1);
}

int			ls_sort_name_r(t_list *prev, t_list *new)
{
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 0 : 1);
}

int			ls_sort_recursive(t_list *prev, t_list *new)
{
	static int	(*f)(t_list *prev, t_list *cur);

	if (!f)
		f = ls_choose_sort(NULL);
	return (((t_ls_info*)(prev->content))->deep <
			((t_ls_info*)(new->content))->deep ? 0 : f(prev, new));
}

void		*ls_set_sort(char (*option)[128])
{
	static int	(*f)(t_list *prev, t_list *cur);

	if ((*option)['R'])
	{
		ls_choose_sort(option);
		f = &ls_sort_recursive;
	}
	else
		f = ls_choose_sort(option);
	return (f);
}

/*
void		*ls_set_sort(char (*option)[128])
{
	static int	(*f)(t_list *prev, t_list *cur);

	if (!f && option)
	{
		if ((*option)['t'])
			f = (*option)['r'] ? &ls_sort_time_mod_r : &ls_sort_time_mod;
		else if ((*option)['f'])
			f = (*option)['r'] ? &ls_not_sorted_r : &ls_not_sorted;
		else if ((*option)['S'])
			f = (*option)['r'] ? &ls_sort_size_r : &ls_sort_size;
		else if ((*option)['u'])
			f = (*option)['r'] ? &ls_sort_time_acc_r : &ls_sort_time_acc;
		else if ((*option)['U'])
			f = (*option)['r'] ? &ls_sort_time_crea_r : &ls_sort_time_crea;
		else
			f = (*option)['r'] ? &ls_sort_name_r : &ls_sort_name;
		if ((*option)['R'])
			return (&ls_sort_recursive);
	}
	return (f);
}
*/
