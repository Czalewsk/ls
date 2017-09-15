/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:04:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/15 10:16:32 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_display_total(t_list *files)
{
	long unsigned	i;

	i = 0;
	while (files)
	{
		i += ((t_ls_info*)(files->content))->stat.st_blocks;
		files = files->next;
	}
	ft_printf("total %lu\n", i);
}

int			ls_check_perm_x(t_ls_info *file, char dot_files)
{
	if (file && file->name && (dot_files || *file->name != '.'))
	{
		if (!file->stat.st_mode)
		{
			ft_printf("ls: %s: Permission denied\n", file->name);
			return (0);
		}
		if ((file->stat.st_mode & 0000100) || !file->is_folder)
			return (1);
	}
	return (-1);
}

void		ls_display_files(t_ls_list *start, char (*option)[128],
		t_ls_info *file)
{
	t_list		*cur;
	static void	(*f)(t_ls_info*, char, t_list*, t_ls_list*);
	static char	dot_files;
	static char	ext_display;

	(void)file;
	if (!f)
	{
		f = ls_set_display(option);
		dot_files = ((*option)['a']);
		ext_display = ((*option)['l']);
	}
	cur = start->files;
	start->print = cur ? 1 : start->print;
	if (ext_display && cur)
		ls_display_total(start->files);
	if (cur)
		f(cur->content, dot_files, cur, start);
}
