/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_ext2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 17:55:44 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/17 19:19:18 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ls_print_line(char *line, t_ls_ext *info, t_ls_info *file)
{
	t_ls_ln		*ln;
	char		*tmp;

	ln = file->line;
	*line = '\0';
	ft_strncat(line, ln->perms, 13);
	tmp = ft_itoa(ln->link);
	ft_cpy_until_r(line, tmp, ' ', info->link);
	free(tmp);
	ft_cpy_until_r(line, ln->owner, ' ', info->user+ 1);
	ft_strcat(line, "  ");
	ft_cpy_until(line, ln->group, ' ', info->group + 1);
	tmp = ft_itoa(ln->size);
	ft_cpy_until_r(line, tmp, ' ', info->size + 1);
	ft_strcat(line, " ");
	ft_strncat(line, ln->time, 14);
	ft_strcat(line, file->name);
	ft_printf("%s\n", line);
}

inline static void	ls_create_line(t_list *files, char dot_files,
		t_ls_info *file, t_ls_ext *info)
{
	static time_t		actual;

	if (!actual)
		time(&actual);
	if (ls_check_perm_x(files->content, dot_files) == 1)
		ls_create_ln(file, info, ft_memalloc(sizeof(t_ls_ln)), &actual);
	else
		file->is_display = 1;
}

void				ls_display_ext(t_ls_info *file, char dot_files,
		t_list *files, t_ls_list *start)
{
	t_ls_ext	info;
	char		*line;

	ft_bzero(&info, sizeof(info));
	while (files)
	{
		file = files->content;
		ls_create_line(files, dot_files, file, &info);
		files = files->next;
	}
	files = start->files;
	files && !((t_ls_info*)files->content)->is_display ?
		ft_printf("total %li\n", info.total) : 0;
	line = ft_memalloc(32 + info.link + info.user + info.group + info.size
			+ info.name);
	ft_memset(line, ' ', 31 + info.link + info.user + info.group + info.size
			+ info.name);
	while (files)
	{
		file = files->content;
		file->is_display ? 0 : ls_print_line(line, &info, file);
		files = files->next;
	}
	ft_lstdel(&start->files, &ls_del_files);
}
