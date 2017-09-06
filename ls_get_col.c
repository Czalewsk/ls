/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:21:02 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/06 19:48:29 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_get_col(void)
{
	struct winsize	ws;

	ioctl(1, TIOCGWINSZ, &ws) ? ft_bzero(&ws, sizeof(ws)) : 0;
	return (ws.ws_col);
}

int			ls_get_longer(t_list *files, char dot_files)
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

int			format_line(t_ls_info *file, t_ls_col *col, char **line)
{
	static char		space[257];
	static int		i;

	if (!*space)
		ft_memset(space, ' ', 256);
	ft_strcat(*line, file->name);
	ft_strcat(*line, space + (255 - col->max_len + ft_strlen(file->name)));
	if (i++ >= col->max_entry - 1)
	{
		i = 0;
		return (1);
	}
	return (0);
}

void		ls_format_col(t_ls_list *start, char dot_files, t_list *files,
		t_ls_col *col)
{
	char			*line;
	int				i;
	t_ls_info		*file;
	t_list			*next;

	line = ft_memalloc(col->size_line);
	i = 0;
	while (files)
	{
		file = files->content;
		next = files->next;
		if ((dot_files || *file->name != '.') && !(i++ % col->nb_line))
		{
			if (format_line(file, col, &line) || !next)
			{
				ft_lst_remove(&start->files, files, &ls_del_files);
				ft_printf("%s\n", line);
				ft_strdel(&line);
				break ;
			}
			ft_lst_remove(file->files ? &file->files : &start->files,
					files, &ls_del_files);
		}
		files = next;
	}
	ft_strdel(&line);
}
