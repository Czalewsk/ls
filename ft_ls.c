/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:08:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/21 15:06:05 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_del_ln_struct(t_ls_ln **line)
{
	ft_strdel(&(*line)->owner);
	ft_strdel(&(*line)->group);
	ft_memdel((void**)line);
}

inline void		ls_del_folders(void *content, size_t size)
{
	t_ls_info	*tmp;

	(void)size;
	tmp = content;
	if (tmp->name)
		ft_strdel(&tmp->name);
	ft_strdel(&tmp->path);
	if (tmp->dir)
		closedir(tmp->dir);
	if (tmp->line)
		ls_del_ln_struct(&tmp->line);
	ft_memdel(&content);
}

inline void		ls_del_files(void *content, size_t size)
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
	if (tmp->line)
		ls_del_ln_struct(&tmp->line);
	ft_memdel(&content);
}

void			ft_ls(int ac, char **av, char (*option)[128])
{
	t_ls_list	start;

	ft_bzero(&start, sizeof(start));
	ls_init_list(&start, ac, av, option);
	ls_wrapper(option, &start);
}
