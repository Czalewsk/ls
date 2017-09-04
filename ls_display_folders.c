/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/04 12:06:17 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128], int *i)
{
	static int	(*f)(t_list *, t_list*);
	static char	recursive;
	static char	dot_files;

	if (!f)
	{
		f = ls_set_sort(option);
		recursive = (*option)['R'];
		dot_files = (*option)['a'];
	}
	if (recursive && (new->stat.st_mode & 0040000) &&
			(*new->name != '.' || dot_files) && 
			ft_strcmp(new->name, ".") && ft_strcmp(new->name, ".."))
	{
		new->is_folder = 1;
		new->err = (new->dir = opendir(new->path)) ? 0 : 1;
		ft_lst_add_index(&start->folders,
				ft_lstnew(new, sizeof(t_ls_info)), (*i)++);
	}
	ft_lstinsert_if_end(&start->files,
			ft_lstnew(new, sizeof(t_ls_info)), f);
}

static int		ls_init_files(t_ls_list *start, t_ls_info *folder,
		char (*option)[128], int *i)
{
	t_ls_info		new;
	struct dirent	*data;

	if (!folder || !folder->dir || folder->err)
		return (0);
	while ((data = readdir(folder->dir)))
	{
		ft_bzero(&new, sizeof(t_ls_info));
		new.name = ft_strdup(data->d_name);
		new.path = ft_strjoin(folder->path, new.name);
		new.path = ft_strjoin_free(new.path, 1, "/", 0);
		lstat(new.path, &new.stat);
		ls_add_to_list(start, &new, option, i);
	}
	return (1);
}

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;
	t_ls_info		*folder;
	t_list			*prev;
	int				i;

	ft_lstlen(start->folders) > 1 ? start->print = 1 : 0;
	folders = start->folders;
	while (folders)
	{
		i = 0;
		folder = folders->content;
		prev = folders;
		ls_init_files(start, folder, option, &i);
		if (!folder->err)
		{
			start->print ? ft_printf("\n%s:\n", folder->name) : 0;
			ls_display_files(start, option);
		}
		else
			ft_printf("\nls: %s: Permission denied(%s)\n", folder->name, folder->path);
		ft_lst_remove(&start->folders, prev, &ls_del_folders);
		folders = start->folders;
	}
}
