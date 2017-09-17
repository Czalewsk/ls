/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_set_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 07:57:25 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/17 17:57:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_display_line(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start)
{
	while (files)
	{
		file = files->content;
		if (ls_check_perm_x(files->content, dot_files) == 1)
			ft_printf("%s\n", file->name);
		files = files->next;
	}
	ft_lstdel(&start->files, &ls_del_files);
}

void		*ls_set_display(char (*option)[128])
{
	static void	(*f)(t_ls_info*, char, t_list*, t_ls_list*);

	if (!f)
	{
		if ((*option)['l'])
			f = &ls_display_ext;
		else if ((*option)['1'])
			f = &ls_display_line;
		else
			f = &ls_display_col;
	}
	return (f);
}
