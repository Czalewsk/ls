/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:08:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/22 12:51:26 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_del_dir(void *content, size_t size)
{
	(void)size;
	if (((t_ls_info*)content)->dir)
		closedir(((t_ls_info*)content)->dir);
	ft_memdel(&content);
}

int			sort_entry_byname(t_list *prev, t_list *new)
{
	return (ft_strcmp(((t_ls_info*)prev->content)->name,
				((t_ls_info*)new->content)->name) < 0 ? 1 : 0);
}

t_list		*sort_entry(int ac, char **av, int i)
{
	t_list		*start;
	t_ls_info	new;

	start = NULL;
	while (i < ac)
	{
		new.name = av[i];
		ft_lstinsert_if_end(&start,
				ft_lstnew(&new, sizeof(t_ls_info)), &sort_entry_byname);
		i++;
	}
	return (start);
}

void		open_each_dir(t_list **start)
{
	t_list		*tmp;
	void		*dir;
	t_ls_info	*elmt;
	t_list		*next;

	tmp = *start;
	while (tmp)
	{
		next = tmp->next;
		elmt = tmp->content;
		if (!(dir = opendir(elmt->name)))
		{
			ft_printf("ls: %s: No such file or directory\n", (elmt->name));
			ft_lst_remove(start, tmp, &ls_del_dir);
		}
		else
			elmt->dir = dir;
		tmp = next;
	}
}

void		ft_ls(int ac, char **av, int i, char (*option)[128])
{
	t_list			*start;
	t_list			*tmp;

	(void)option;
	start = sort_entry(ac, av, i);
	open_each_dir(&start);
	tmp = start;
	ft_lstdel(&start, &ls_del_dir);
}
