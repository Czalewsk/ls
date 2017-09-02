/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:08:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/02 18:41:50 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_del_dir(void *content, size_t size)
{
	t_ls_info	*tmp;

	(void)size;
	tmp = content;
	ft_strdel(&tmp->name);
	if (tmp->path)
		ft_strdel(&tmp->path);
//	if (tmp->data)
//	    ft_memdel((void**)&tmp->data);
	if (tmp->dir)
		closedir(tmp->dir);
	ft_memdel(&content);
}

void		ft_ls(int ac, char **av, int i, char (*option)[128])
{
	t_ls_list	start;

	start.folders = NULL;
	start.files = NULL;
	start.error = NULL;
	start.print = 0;
	ls_init_list(&start, ac, av, i, option);
	ls_wrapper(option, &start);
}
