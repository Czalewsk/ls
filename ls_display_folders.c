/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/02 19:59:55 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_add_to_list(t_ls_list *start, t_ls_info *new,
		char (*option)[128], t_ls_info *folder, int *i)
{
	static int		(*f)(t_list *, t_list*);
	static char		recursive;
	struct dirent	*data;

	if (!f)
	{
		f = ls_set_sort(option);
		recursive = (*option)['R'];
	}
	ft_printf("folder->dir======%p\n", folder->dir);
	while ((data = readdir(folder->dir)))
	{
		ft_printf("NAME---%s\n", data->d_name);
		new->name = ft_strdup(data->d_name);
		new->path = ft_strjoin(folder->path, new->name);
		new->path = ft_strjoin_free(new->path, 1, "/", 0);
		new->err = lstat(new->path, &new->stat) ? 1 : 0;
		new->dir = NULL;
		if (recursive && !new->err && (new->stat.st_mode & 0040000)
				&& ft_strcmp(new->name, ".") && ft_strcmp(new->name, ".."))
		{
			if((new->dir = opendir(new->name)))
			ft_lst_add_index(&start->folders,
					ft_lstnew(new, sizeof(t_ls_info)), (*i)++);
			else
				ft_printf("ERRRRRRRRROOOOOOOOOOOr\n");
		}
		ft_lstinsert_if_end(&start->files, ft_lstnew(new, sizeof(t_ls_info)), f);
	}
}

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;
	t_ls_info		new;
	int				i;

	folders = start->folders;
	while (folders)
	{
		i = 0;
		ft_printf("\n%s:\n", ((t_ls_info*)(folders->content))->name);
		ft_bzero(&new, sizeof(t_ls_info));
		ls_add_to_list(start, &new, option, folders->content, &i);
		ls_display_files(start, option);
		ft_printf("ADRESSSSSSSEE=%p\n", folders);
		ft_lst_remove(&start->folders, folders, &ls_del_dir);
		ft_printf("ADRESSSSSSSEE=%p\n", start->folders);
		folders = start->folders;
	}
}
