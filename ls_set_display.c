/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_set_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 07:57:25 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/17 08:14:56 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_print_line(char *line, t_ls_ext *info, t_ls_info *file)
{
	t_ls_ln		*ln;
	char		*tmp;

	ln = file->line;
	*line = '\0';
	ft_strncat(line, ln->perms, 13);
	tmp = ft_itoa(ln->link);
	ft_cpy_until_r(line, tmp, ' ', info->link + 1);
	free(tmp);
	ft_cpy_until_r(line, ln->owner, ' ', info->user + 1);
	ft_strcat(line, "  ");
	ft_cpy_until(line, ln->group, ' ', info->group + 1);
	tmp = ft_itoa(ln->size);
	ft_cpy_until_r(line, tmp, ' ', info->size);
	ft_printf("%s|\n", line);
}

static void	ls_display_ext(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start)
{
	t_ls_ext	info;
	time_t		actual;
	char		*line;

	time(&actual);
	ft_bzero(&info, sizeof(info));
	while (files)
	{
		file = files->content;
		if (ls_check_perm_x(files->content, dot_files) == 1)
			ls_create_ln(file, &info, ft_memalloc(sizeof(t_ls_ln)), &actual);
		else
			file->is_display = 1;
		files = files->next;
	}
	files = start->files;
	line = ft_memalloc(32 + info.link + info.user + info.group + info.size
			+ info.name);
	ft_memset(line, ' ', 31 + info.link + info.user + info.group + info.size
			+ info.name);
	while (files)
	{
		file = files->content;
		if (!file->is_display)
			ls_print_line(line, &info, file);
		files = files->next;
	}
	ft_lstdel(&start->files, &ls_del_files);
	ft_printf("total=%d\n", info.total);
	ft_printf("name=%d\n", info.name);
	ft_printf("link =%d\n", info.link);
	ft_printf("user =%d\n", info.user);
	ft_printf("group=%d\n", info.group);
	ft_printf("size =%d\n", info.size);
	ft_printf("size_line=%d\n", 32 + info.link + info.user + info.group +
			info.size + info.name);
}

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
