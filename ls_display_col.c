/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 08:36:09 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/14 10:27:09 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_init_col(t_ls_col *col, t_list *files, char dot_files)
{
	int		lst_len;

	lst_len = ft_lstlen(files);
	col->col = ls_get_col();
	col->max_len = ls_get_longer(files, dot_files);
	col->max_entry = col->col / (col->max_len + 1);
	col->max_entry = col->max_entry > 0 ? col->max_entry : 1;
	col->size_line = col->max_entry > 1 ? col->col + 1 : col->max_len + 1;
	col->nb_line = (lst_len / col->max_entry) + (lst_len % col->max_entry);
	col->nb_line = col->nb_line > 0 ? col->nb_line : 1;
}

void		ls_display_col(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start)
{
	static t_ls_col		col;
	int					i;

	i = 0;
	if (!col.max_entry)
		ft_bzero(&col, sizeof(col));
	if (file)
		ls_init_col(&col, files, dot_files);
	while (col.nb_line >= 0)
	{
		ls_format_col(start, dot_files, start->files, &col);
		col.nb_line--;
	}
	ft_lstdel(&start->files, &ls_del_files);
}
