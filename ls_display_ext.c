/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 10:52:34 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/17 07:37:57 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_fill_perm(unsigned long mode, char *file_mode)
{
	*file_mode = mode & 4 ? 'r' : '-';
	*(file_mode + 1) = mode & 2 ? 'w' : '-';
	*(file_mode + 2) = mode & 1 ? 'x' : '-';
}

int			ls_fill_mode(t_ls_info *file, unsigned long mode)
{
	int					i;
	char				*file_mode;
	const t_ls_entry	entry_char[7] = { {S_IFIFO, 'p'}, {S_IFLNK, 'l'},
		{S_IFDIR, 'd'}, {S_IFBLK, 'b'}, {S_IFREG, '-'}, {S_IFCHR, 'c'},
		{S_IFSOCK, 's'}, };

	i = -1;
	file_mode = file->line->perms;
	*file_mode = ' ';
	while (++i < 7 && *file_mode == ' ')
		if (entry_char[i].type == (int)(mode & S_IFMT))
			*file_mode = entry_char[i].match;
	i = -1;
	while (++i < 3)
		ls_fill_perm(mode >> (6 - 3 * i), file_mode + 1 + (i * 3));
	*(file_mode + 9) = ((mode & 1000) == 1000) && (mode & S_IXOTH) == S_IXOTH ?
		't' : *(file_mode + 9);
	*(file_mode + 9) = ((mode & 1000) == 1000) &&
		!((mode & S_IXOTH) == S_IXOTH) ? 'T' : *(file_mode + 9);
	*(file_mode + 10) = (file->stat.st_flags &&
		listxattr(file->path, NULL, 0, XATTR_NOFOLLOW) > 0) ? '@' : ' ';
	*(file_mode + 10) = (*(file_mode + 10) == ' ' &&
			file->stat.st_flags & 0x100000) ? '+' : *(file_mode + 10);
	*(file_mode + 11) = ' ';
	return (1);
}

void		ls_get_owner_and_group(t_ls_ext *info, t_ls_ln *line,
		struct passwd *pswd, struct group *grp)
{
	int		i;
	char	*tmp;

	tmp = grp ? grp->gr_name : NULL;
	line->group = tmp;
	i = ft_strlen(tmp);
	info->group = info->group > i ? info->group : i;
	tmp = pswd ? pswd->pw_name : NULL;
	line->owner = tmp;
	i = ft_strlen(tmp);
	info->user = info->user > i ? info->user : i;
}

void		ls_get_time(t_ls_ln *line, time_t *time, time_t *actual)
{
	char	*time_area;
	char	*time_char;

	time_area = line->time;
	time_char = ctime(time) + 4;
	ft_strncat(time_area, time_char, 7);
	ft_abs(*actual, *time) > 15770000 ?
		ft_strncat(time_area, time_char + 15, 5) : 
		ft_strncat(time_area, time_char + 7, 5);
//	write(1, time_area, 13);
}

void		ls_create_ln(t_ls_info *file, t_ls_ext *info, t_ls_ln *new,
		time_t *actual)
{
	struct stat		*stat;
	int				i;

	stat = &file->stat;
	file->line = new;
	i = ft_strlen(file->name);
	info->name = info->name > i ? info->name : i;
	ls_fill_mode(file, stat->st_mode) && !(i = 0);
	new->size = stat->st_size;
	(i = file->stat.st_blocks) ? info->total += i : 0;
	i = stat->st_nlink;
	new->link = i;
	i = ft_ulintlen(i);
	info->link = info->link > i ? info->link : i;
	i = stat->st_size;
	new->size = i;
	i = ft_ulintlen(i);
	info->size = info->size > i ? info->size : i;
	ls_get_owner_and_group(info, new,
			getpwuid(stat->st_uid), getgrgid(stat->st_gid));
	ls_get_time(new, &stat->st_mtime, actual);
	//ft_printf("  %lu %s  %s  %lu  %s\n", new->link, new->owner, new->group,
	//		new->size, file->name);
}
