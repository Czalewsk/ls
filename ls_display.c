/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:04:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/23 20:37:51 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_display_line(t_ls_info *file, char dot_files)
{
	if (dot_files || *file->name != '.')
		ft_printf("%s\n", file->name);
}

static void	ls_display_col(t_ls_info *file, char dot_files)
{
	if (dot_files || *file->name != '.')
		ft_printf("%s\n", file->name);
}

static void	ls_display_ext(t_ls_info *files, char dot_files)
{
	(void)files;
	(void)dot_files;
}

void	*ls_set_display(char (*option)[128])
{
	void	(*f)(t_ls_info*, char);

	if ((*option)['l'])
		f = &ls_display_ext;
	else if ((*option)['1'])
		f = &ls_display_line;
	else
		f = &ls_display_col;
	return (f);
}

void	ls_display_files(t_ls_list *start, char (*option)[128])
{
	t_list		*prev;
	t_list		*cur;
	static void	(*f)(t_ls_info*, char);
	static char	dot_files;

	if (!f)
	{
		f = ls_set_display(option);
		if ((*option)['a'])
			dot_files = 1;
	}
	cur = start->files;
	while (cur)
	{
		f(cur->content, dot_files);
		prev = cur;
		cur = cur->next;
		ft_lst_remove(&start->files, prev, &ls_del_dir);
	}
}