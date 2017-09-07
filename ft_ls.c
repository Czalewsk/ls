/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:08:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/07 08:16:40 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_del_folders(void *content, size_t size)
{
	t_ls_info	*tmp;

	(void)size;
	tmp = content;
	if (tmp->name)
		ft_strdel(&tmp->name);
//	if (tmp->files)
//		ft_lstdel(&tmp->files, &ls_del_files);
	ft_strdel(&tmp->path);
	if (tmp->dir)
		closedir(tmp->dir);
	ft_memdel(&content);
}

void		ls_del_files(void *content, size_t size)
{
	t_ls_info	*tmp;

	(void)size;
	tmp = content;
	if (!tmp->is_folder)
	{
		ft_strdel(&tmp->name);
		if (tmp->path)
			ft_strdel(&tmp->path);
		if (tmp->dir)
			closedir(tmp->dir);
	}
	ft_memdel(&content);
}

void		ft_ls(int ac, char **av, char (*option)[128])
{
	t_ls_list	start;

	ft_bzero(&start, sizeof(start));
	ls_init_list(&start, ac, av, option);
	ls_wrapper(option, &start);
}
