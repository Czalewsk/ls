/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/04 17:57:50 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128], t_ls_info *folder)
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
		ft_lstinsert_if_end(&start->folders,
				ft_lstnew(new, sizeof(t_ls_info)), f);
	}
	ft_lstinsert_if_end(&folder->files,
			ft_lstnew(new, sizeof(t_ls_info)), f);
}

static int		ls_init_files(t_ls_list *start, t_ls_info *folder,
		char (*option)[128])
{
	t_ls_info		new;
	struct dirent	*data;
	static long		i;

	if (!folder || !folder->dir || folder->err)
		return (0);
	i++;
	while ((data = readdir(folder->dir)))
	{
		ft_bzero(&new, sizeof(t_ls_info));
		new.deep = i;
		new.name = ft_strdup(data->d_name);
		new.path = ft_strjoin(folder->path, "/");
		new.path = ft_strjoin_free(new.path, 1, new.name, 0);
		lstat(new.path, &new.stat);
		ls_add_to_list(start, &new, option, folder);
	}
	return (1);
}

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;
	t_ls_info		*folder;
	t_list			*prev;
	int				i;

	folders = start->folders;
	while (folders)
	{
		i = 0;
		folder = folders->content;
		prev = folders;
		start->print ? write(1, "\n", 1) : 0;
		start->print || ft_lstlen(start->folders) > 1 ?
			ft_printf("%s:\n", folder->path) : 0;
		ls_init_files(start, folder, option);
		if (!folder->err)
			ls_display_files(start, option, folder->files);
		else if ((start->print = 1))
			ft_printf("ls: %s: Permission denied\n", folder->name);
		ft_lst_remove(&start->folders, prev, &ls_del_folders);
		folders = start->folders;
	}
}
