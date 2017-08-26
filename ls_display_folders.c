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


	if (!f)
	{
		f = ls_set_sort(option);
		recursive = (*option)['R'];
	}
	new.data = ft_memdup(data, sizeof(struct dirent));
	new.name = (new.data)->d_name;
	lstat(new.name, &new.stat);
	new.dir = NULL;
	ft_lstinsert_if_end(&start->files, ft_lstnew(&new, sizeof(t_ls_info)), f);
	if (recursive && (new.stat.st_mode & 0040000))
	{
		new.dir = opendir(new.name);
		ft_lst_add_index(&start->files,
				ft_lstnew(&new, sizeof(t_ls_info)), (*i)++);
	}
}

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;
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
		while ((data = readdir(folder->dir)))
			ls_add_to_files(start, data, option, &i);
		if (start->print)
			ft_printf("%s:\n", folder->name);
		ls_display_files(start, option);
		ft_lst_remove(&start->folders, folders, &ls_del_dir);
		folders = start->folders;
	}
}