/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:04:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/07 10:17:55 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_display_line(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start)
{
	if (file && (dot_files || *file->name != '.'))
		ft_printf("%s\n", file->name);
	if (start && file && files)
		ft_lst_remove_index(&start->files, 0, &ls_del_files);
}

static void	ls_display_col(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start)
{
	static t_ls_col		col;
	int					i;

	i = 0;
	if (!file)
	{
		ft_bzero(&col, sizeof(col));
		ft_lstdel(&start->files, &ls_del_files);
		return ;
	}
	else if (file && !col.max_entry)
	{
		col.col = ls_get_col();
		col.max_len = ls_get_longer(files, dot_files);
		col.max_entry = col.col / (col.max_len + 1);
		col.max_entry = col.max_entry > 0 ? col.max_entry : 1;
		col.size_line = col.max_entry > 1 ? col.col + 1 : col.max_len + 1;
		col.nb_line = (ft_lstlen(files) / col.max_entry);
		col.nb_line = col.nb_line > 0 ? col.nb_line : 1;
	}
	ls_format_col(start, dot_files, start->files, &col);
	col.nb_line--;
}

static void	ls_display_ext(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start)
{
	(void)start;
	(void)files;
	(void)file;
	(void)dot_files;
	ft_lst_remove(&start->files, files, &ls_del_files);
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

void		ls_display_files(t_ls_list *start, char (*option)[128],
		t_ls_info *file)
{
	t_list		*cur;
	t_list		*next;
	static void	(*f)(t_ls_info*, char, t_list*, t_ls_list*);
	static char	dot_files;

	if (!f)
	{
		f = ls_set_display(option);
		dot_files = ((*option)['a']);
	}
	cur =  start->files;
	start->print = cur ? 1 : start->print;
	while (cur)
	{
		next = cur->next;
		file = cur->content;
		if (!file->stat.st_mode && (dot_files || *file->name != '.'))
			ft_printf("ls: %s: Permission denied\n", file->name);
		else if ((file->stat.st_mode & 0000100) || !file->is_folder)
			f(file, dot_files, cur, start);
		cur = next;
	}
	f(NULL, 0, NULL, start);
}
