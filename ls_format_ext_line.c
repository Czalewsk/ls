/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_format_ext_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:20:17 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/19 08:36:39 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	ls_print_link(t_ls_info *file, char *line)
{
	char		link[256];
	int			ret;

	ret = readlink(file->path, link, 256);
	link[ret != -1 ? ret : 0] = '\0';
	ft_printf("%s -> %s\n", line, link);
}

static inline int	ls_add_min_maj(char *line, t_ls_info *file)
{
	char	type;
	char	*tmp;

	type = *line;
	if (!(type == 'c' || type == 'b'))
		return((int)ft_strcat(line, "       "));
	else
	{
		tmp = ft_itoa(major(file->stat.st_rdev));
		ft_cpy_until_r(line, tmp, ' ', 4);
		ft_strcat(line, ",");
		free(tmp);
		tmp = ft_itoa(minor(file->stat.st_rdev));
		ft_cpy_until_r(line, tmp, ' ', 4);
		free(tmp);
	}
	return (0);
}

void				ls_format_line_n(char *line, t_ls_ext *info,
		t_ls_info *file)
{
	t_ls_ln		*ln;
	char		*tmp;

	ln = file->line;
	*line = '\0';
	ft_strncat(line, ln->perms, 13);
	(tmp = ft_itoa(ln->link));
	ft_cpy_until_r(line, tmp, ' ', info->link);
	ft_strcat(line, " ");
	free(tmp);
	ft_cpy_until(line, ln->owner, ' ', info->user + 2);
	ft_cpy_until(line, ln->group, ' ', info->group + 1);
	(tmp = ft_itoa(ln->size));
	ft_cpy_until_r(line, tmp, ' ', info->size + 1);
	free(tmp);
	ft_strcat(line, " ");
	ft_strncat(line, ln->time, 14);
	ft_strcat(line, file->name);
	*line != 'l'? ft_putendl(line) : ls_print_link(file, line);
}

void				ls_format_line_m(char *line, t_ls_ext *info,
		t_ls_info *file)
{
	t_ls_ln		*ln;
	char		*tmp;

	ln = file->line;
	*line = '\0';
	ft_strncat(line, ln->perms, 13);
	(tmp = ft_itoa(ln->link));
	ft_cpy_until_r(line, tmp, ' ', info->link);
	ft_strcat(line, " ");
	free(tmp);
	ft_cpy_until(line, ln->owner, ' ', info->user + 2);
	ft_cpy_until(line, ln->group, ' ', info->group + 1);
	if(ls_add_min_maj(line, file))
	{
		(tmp = ft_itoa(ln->size));
		ft_cpy_until_r(line, tmp, ' ', info->size + 1);
		free(tmp);
	}
	ft_strcat(line, " ");
	ft_strncat(line, ln->time, 14);
	ft_strcat(line, file->name);
	*line != 'l'? ft_putendl(line) : ls_print_link(file, line);
}
