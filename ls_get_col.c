/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:21:02 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/05 16:29:34 by czalewsk         ###   ########.fr       */
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

void		ls_format_col(t_ls_info *file, char dot_files, t_list *files,
		t_ls_col *col)
{
	char			*line;
	int				i;
	int				d;
	static char		space[256];
	//t_list		*prev;

	ft_printf("SIZE = %d\n", col->size_line);
	line = ft_memalloc(col->size_line);
	if (!*space)
		ft_memset(space, ' ', 255);
	i = 0;
	while (files && i++ < col->max_entry && !(d = 0))
	{
		file = files->content;
		if ((dot_files || *file->name != '.') && !(d++ % col->max_entry))
		{
			ft_strcat(line, file->name);
			ft_strcat(line, space + (255 - ft_strlen(file->name)));
		//	ft_lst_remove(&start->files, prev, &ls_del_files);
		}
		files = files->next;
	}
	ft_printf("%s\n", line);
	ft_strdel(&line);
}
