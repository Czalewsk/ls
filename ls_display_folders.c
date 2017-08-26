/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/26 16:27:50 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_add_to_files(t_ls_list *start, struct dirent *data,
		char(*option)[128])
{
	t_ls_info	new;
	static int	(*f)(t_list *, t_list *);

	if (!f)
		f = ls_set_sort(option);
	new.data = ft_memdup(data, sizeof(struct dirent));
	new.name = (new.data)->d_name;
	lstat(new.name, &new.stat);
	new.dir = opendir(new.name);
	ft_lstinsert_if_end(&start->files, ft_lstnew(&new, sizeof(t_ls_info)), f);
}

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list		*folders;
	t_ls_info	*folder;

	if (ft_lstlen(start->folders) > 1)
		start->print = 1;
	folders = start->folders;
	while (folders)
	{
		folder = folders->content;
		while ((folder->data = readdir(folder->dir)))
			ls_add_to_files(start, folder->data, option);
		ls_display_files(start, option);
		ft_lst_remove_index(&start->folders, 0, &ls_del_dir);
		folders = start->folders;
	}
}