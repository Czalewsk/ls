/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:58:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/04 10:00:32 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128])
{
	static int	(*f)(t_list *, t_list*);

	if (!f)
		f = ls_set_sort(option);
	if (new->stat.st_mode & 0040000)
	{
		new->err = (new->dir = opendir(new->name)) ? 0 : 1;
		ft_lstinsert_if_end(&start->folders,
				ft_lstnew(new, sizeof(t_ls_info)), f);
	}
	else
	{
		new->dir = NULL;
		ft_lstinsert_if_end(&start->files,
				ft_lstnew(new, sizeof(t_ls_info)), f);
	}
}

void	ls_init_list(t_ls_list *start, int ac, char **av, int i,
		char (*option)[128])
{
	t_ls_info		new;

	ft_bzero(&new, sizeof(t_ls_info));
	if (i == ac)
	{
		new.dir = opendir(".");
		new.name = ft_strdup(".");
		new.path = ft_strdup("./");
		lstat(new.name, &new.stat);
		ft_lstadd(&start->folders, ft_lstnew(&new, sizeof(t_ls_info)));
	}
	while (i < ac)
	{
		new.name = ft_strdup(av[i]);
		new.path = ft_strjoin(new.name, "/");
		if (lstat(new.name, &new.stat))
			ft_lstinsert_if_end(&start->error,
					ft_lstnew(&new, sizeof(t_ls_info)), &ls_sort_name);
		else
			ls_add_to_list(start, &new, option);
		i++;
	}
}
