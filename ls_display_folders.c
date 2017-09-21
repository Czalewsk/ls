/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/21 17:20:22 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

inline static int	ls_is_not_root(char *name)
{
	int		len;

	if (!name)
		return (0);
	len = ft_strlen(name);
	if (len > 2)
		return (1);
	else if (len == 1 && *name == '.')
		return (0);
	else if (len == 2 && *name == '.' && *(name + 1) == '.')
		return (0);
	else
		return (1);
}

inline static int	ls_check_dot_files(t_ls_info *new, char dot_files)
{
	if (*new->name == '.' && !dot_files)
	{
		ft_strdel(&new->name);
		ft_strdel(&new->path);
		return (0);
	}
	return (1);
}

inline static void	ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128])
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
	if (!ls_check_dot_files(new, dot_files))
		return ;
	if (recursive && ((new->stat.st_mode & S_IFMT) == S_IFDIR) &&
		(*new->name != '.' || dot_files) && ls_is_not_root(new->name))
	{
		new->is_folder = 1;
		new->err |= (new->dir = opendir(new->path)) ? 0 : 1;
		ft_lstinsert_if_end(&start->folders,
				ft_lstnew(new, sizeof(t_ls_info)), f);
	}
	ft_lstinsert_if_end(&start->files,
			ft_lstnew(new, sizeof(t_ls_info)), f);
}

static int			ls_init_files(t_ls_list *start, t_ls_info *folder,
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
		new.path = folder->slash ?
			ft_strdup(folder->path) : ft_strjoin(folder->path, "/");
		new.path = ft_strjoin_free(new.path, 1, new.name, 0);
		lstat(new.path, &new.stat);
		ls_add_to_list(start, &new, option);
	}
	return (1);
}

void				ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;
	t_ls_info		*folder;
	int				i;

	folders = start->folders;
	while (folders)
	{
		i = 0;
		folder = folders->content;
		start->print ? write(1, "\n", 1) : 0;
		start->print || ft_lstlen(start->folders) > 1 ?
			ft_printf("%s:\n", folder->path) && (start->print = 1) : 0;
		ls_init_files(start, folder, option);
		if (!folder->err)
			ls_display_files(start, option, folder);
		if ((folder->err || !(folder->stat.st_mode & S_IXUSR))
				&& (start->print = 1))
			ft_printf("ls: %s: Permission denied\n", folder->name);
		ft_lst_remove(&start->folders, folders, &ls_del_folders);
		folders = start->folders;
	}
	ft_lstdel(&start->files, &ls_del_files);
}
