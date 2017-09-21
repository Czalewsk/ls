/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:58:24 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/21 17:20:37 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128])
{
	static int	(*f)(t_list *, t_list*);

	if (!f)
		f = ls_set_sort(option);
	if ((new->stat.st_mode & S_IFMT) == S_IFDIR)
	{
		new->err |= (new->dir = opendir(new->name)) ? 0 : 1;
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

void		ls_no_path(t_ls_info *new, t_ls_list *start)
{
	new->dir = opendir(".");
	new->name = ft_strdup(".");
	new->path = ft_strdup(".");
	stat(new->name, &new->stat);
	ft_lstadd(&start->folders, ft_lstnew(new, sizeof(t_ls_info)));
}

void		ls_init_list(t_ls_list *start, int ac, char **av,
		char (*option)[128])
{
	t_ls_info		new;
	int				i;
	int				l;

	ft_bzero(&new, sizeof(t_ls_info));
	i = get_param(0, NULL, NULL);
	if (i == ac)
		ls_no_path(&new, start);
	while (i < ac)
	{
		ft_bzero(&new, sizeof(t_ls_info));
		new.name = ft_strdup(av[i]);
		l = ft_strlen(av[i]);
		if (l >= 1 && (av[i][l - 1] == '/'))
			new.slash = 1;
		new.path = ft_strdup(av[i]);
		if ((new.err = lstat(new.path, &new.stat) ? errno : 0))
			ft_lstinsert_if_end(&start->error,
					ft_lstnew(&new, sizeof(t_ls_info)), &ls_sort_name);
		else
			ls_add_to_list(start, &new, option);
		i++;
	}
}
