/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:58:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/23 20:44:47 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128])
{
	static int	(*f)(t_list *, t_list*);

	if (!f)
		f = ls_set_sort(option);
	if (new->stat.st_mode & 0100000)
		ft_lstinsert_if_end(&start->files,
				ft_lstnew(new, sizeof(t_ls_info)), f);
	else
	{
		((new->dir = opendir(new->name)));
		ft_lstinsert_if_end(&start->folders,
				ft_lstnew(new, sizeof(t_ls_info)), f);
	}
}

void	ls_init_list(t_ls_list *start, int ac, char **av, int i,
		char (*option)[128])
{
	t_ls_info		new;

	if (i == ac)
	{
		new.dir = opendir(".");
		new.name = ".";
		lstat(new.name, &new.stat);
		ft_lstadd(&start->folders, ft_lstnew(&new, sizeof(t_ls_info)));
	}
	while (i < ac)
	{
		new.name = av[i];
		if (lstat(new.name, &new.stat))
		{
			ft_lstinsert_if_end(&start->error,
				ft_lstnew(&new, sizeof(t_ls_info)), &ls_sort_name);
		}
		else
			ls_add_to_list(start, &new, option);
		i++;
	}
}
