/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 10:52:34 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/16 12:34:22 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_create_ln(t_ls_info *file, t_ls_ext *info)
{
	struct stat		*stat;
	int				i;
	struct passwd	*pswd;
	struct group	*grp;

	stat = &file->stat;
//	fill_mode(file);
	info->total += file->stat.st_blocks;
	i = ft_ulintlen(stat->st_nlink);
	info->link = info->link > i ? info->link : i;
	pswd = getpwuid(stat->st_uid);
	i = pswd ? ft_strlen(pswd->pw_name) : 0;
	info->user = info->user > i ? info->user : i;
	grp = getgrgid(stat->st_gid);
	i = grp ? ft_strlen(grp->gr_name) : 0;
	info->group = info->group > i ? info->group : i;
	i = ft_ulintlen(stat->st_size);
	info->size = info->size > i ? info->size : i;
}
