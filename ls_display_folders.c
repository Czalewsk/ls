/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/26 20:21:45 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_add_to_files(t_ls_list *start, struct dirent *data,
		char(*option)[128], int *i)
{
	t_ls_info	new;
	static int	(*f)(t_list *, t_list *);
	static char	recursive;
	static char dot_files;

	if (!f)
	{
	    dot_files = (*option)['a'];
		f = ls_set_sort(option);
		recursive = (*option)['R'];
	}
	new.data = ft_memdup(data, sizeof(struct dirent));
	new.name = (new.data)->d_name;
	new.path = ft_strjoin(((t_ls_info*)(start->folders->content))->path, new.name);
	new.path = ft_strjoin_free(new.path, 1, "/", 0);
	new.err = lstat(new.path, &new.stat) ? 1 : 0;
	new.dir = NULL;
	ft_lstinsert_if_end(&start->files, ft_lstnew(&new, sizeof(t_ls_info)), f);
	if (recursive && !new.err && (new.stat.st_mode & 0040000) && (*i)++ > 1 
	        && (dot_files || (!dot_files && *new.name != '.')))
	{
		new.dir = opendir(new.path);
		ft_lst_pushend(&start->folders,
				ft_lstnew(&new, sizeof(t_ls_info)));
	}
}

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;
	t_list			*prev;
	t_ls_info		*folder;
	struct dirent	*data;
	int				i;

	if (ft_lstlen(start->folders) > 1)
		start->print = 1;
	folders = start->folders;
	while (folders)
	{
		i = 0;
		folder = folders->content;
		if (start->print)
			ft_printf("\n%s:\n", folder->name);
		if (!folder->dir)
		    ft_printf("error\n");
		else
		    while ((data = readdir(folder->dir)))
		        ls_add_to_files(start, data, option, &i);
		ls_display_files(start, option);
		prev = folders;
		folders = folders->next;
		ft_lst_remove(&start->folders, prev, &ls_del_dir);
	}
}
