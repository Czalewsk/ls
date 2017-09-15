/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:21:02 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/15 11:04:14 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

inline int		ls_get_col(void)
{
	struct winsize	ws;

	ioctl(1, TIOCGWINSZ, &ws) ? ft_bzero(&ws, sizeof(ws)) : 0;
	return (ws.ws_col);
}

inline int		ls_get_longer(t_list *files, char dot_files)
{
	t_ls_info		*file;
	int				longer;
	int				cur;

	longer = 0;
	cur = 0;
	while (files)
	{
		file = files->content;
		if (dot_files || *file->name != '.')
			cur = ft_strlen(file->name);
		longer = cur > longer ? cur : longer;
		files = files->next;
	}
	return (longer);
}

int				format_line(t_ls_info *file, t_ls_col *col, char **line)
{
	static char		space[257];

	if (!*space)
		ft_memset(space, ' ', 256);
	file->is_display = 1;
	strcat(*line, file->name);
	if (col->entry++ >= col->max_entry - 1)
		return (1);
	ft_strcat(*line, space + (255 - col->max_len + ft_strlen(file->name)));
	return (0);
}

static int		ls_print_line(t_ls_col *col, char **line)
{
	col->entry = 0;
	ft_putendl(*line);
	ft_strdel(line);
	return (1);
}

int				ls_format_col(t_ls_list *start, char dot_files, t_list *files,
		t_ls_col *col)
{
	char			*line;
	int				i;
	t_ls_info		*file;

	(void)start;
	line = ft_memalloc(col->size_line);
	i = 0;
	while (files)
	{
		file = files->content;
		if (ls_check_perm_x(file, dot_files)
				&& !file->is_display && (dot_files || *file->name != '.')
				&& (!col->nb_line || !(i++ % col->nb_line))
				&& format_line(file, col, &line))
			return (ls_print_line(col, &line));
		files = files->next;
	}
	if (col->entry)
		return (ls_print_line(col, &line));
	ft_strdel(&line);
	return (0);
}
