/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:21:02 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/05 20:53:21 by czalewsk         ###   ########.fr       */
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

void		ls_format_col(t_ls_info *start, char dot_files, t_list *files,
		t_ls_col *col)
{
	char			*line;
	int				i;
	static char		space[257];
	t_ls_info		*file;
	t_list			*next;

	line = ft_memalloc(col->size_line);
	if (!(i = 0) && !*space)
		ft_memset(space, ' ', 256);
	while (files)
	{
		file = files->content;
		if ((dot_files || *file->name != '.') && !(i++ % col->max_entry))
		{
			ft_strcat(line, file->name);
			ft_strcat(line, space + (255 + col->max_len - ft_strlen(file->name)));
			next = files->next;
			ft_lst_remove(&start->files, files, &ls_del_files);
		}
		files = next;
		if (i >= col->max_entry)
			break ;
	}
	ft_printf("%s\n", line);
	ft_strdel(&line);
}
