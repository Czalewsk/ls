/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:04:14 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/05 16:42:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_display_line(t_ls_info *file, char dot_files, t_list *files,
		t_ls_info *start)
{
	if (file && (dot_files || *file->name != '.'))
		ft_printf("%s\n", file->name);
	if (start && file && files)
		ft_lst_remove_index(&start->files, 0, &ls_del_files);
}

static void	ls_display_col(t_ls_info *file, char dot_files, t_list *files, 
		t_ls_info *start)
{
	static t_ls_col		col;

	if (!file)
		ft_bzero(&col, sizeof(col));
	else if (file && !col.max_entry)
	{
		col.col = ls_get_col();
		ft_printf("COL  = %d\n", col.col);
		col.max_len = ls_get_longer(files,dot_files);
		ft_printf("MAX LEN  = %d\n", col.max_len);
		col.max_entry = col.col / (col.max_len + 1);
		col.max_entry = col.max_entry > 0 ? col.max_entry : 1;
		ft_printf("MAX ENTRY =%d\n", col.max_entry);
		col.size_line = col.max_entry > 1 ? col.col + 1: col.max_len + 1;
		if (ft_lstlen(files) == 3 && !dot_files 
				&& ft_printf("%s\n", file->name))
			return ;
	}
	ls_format_col(file, dot_files, files, &col);
	ft_lst_remove(&start->files, files, &ls_del_files);
}

static void	ls_display_ext(t_ls_info *file, char dot_files, t_list *files, 
		t_ls_info *start)
{
	(void)start;
	(void)files;
	(void)file;
	(void)dot_files;
	ft_lst_remove(&start->files, files, &ls_del_files);
}

void		*ls_set_display(char (*option)[128])
{
	static void	(*f)(t_ls_info*, char, t_list*, t_ls_info*);

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
		t_list *files)
{
	t_ls_info	*file;
	t_list		*prev;
	t_list		*cur;
	static void	(*f)(t_ls_info*, char, t_list*, t_ls_list*);
	static char	dot_files;

	if (!f)
	{
		f = ls_set_display(option);
		dot_files = ((*option)['a']);
	}
	cur = files ? files : start->files;
	start->print = cur ? 1 : start->print;
	while (cur)
	{
		file = cur->content;
		prev = cur->next;
		if (!file->stat.st_mode && (dot_files || *file->name != '.'))
			ft_printf("ls: %s: Permission denied\n", file->name);
		else if ((file->stat.st_mode & 0000100) || !file->is_folder)
			f(file, dot_files, cur, start);
		cur = prev;
	}
	f(NULL, 0, NULL, NULL);
}
