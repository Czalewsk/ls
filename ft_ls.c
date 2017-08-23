/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:08:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/23 20:05:18 by czalewsk         ###   ########.fr       */
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

t_list		*sort_entry(int ac, char **av, int i)
{
	t_list		*start;
	t_ls_info	new;

	start = NULL;
	while (i < ac)
	{
		new.dir = NULL;
		new.name = av[i];
		ft_lstinsert_if_end(&start,
				ft_lstnew(&new, sizeof(t_ls_info)), &ls_sort_name);
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
		if (lstat(elmt->name, &elmt->stat))
		{
			ft_printf("ls: %s: No such file or directory\n", (elmt->name));
			ft_lst_remove(start, tmp, &ls_del_dir);
		}
		else if ((dir = opendir(elmt->name)))
			elmt->dir = dir;
		tmp = next;
	}
}

void		ft_ls(int ac, char **av, int i, char (*option)[128])
{
	t_ls_list	start;

	start.error = NULL;
	start.files = NULL;
	start.folders = NULL;
	start.print = 0;
	ls_init_list(&start, ac, av, i, option);
	ls_wrapper(option, &start);
}
