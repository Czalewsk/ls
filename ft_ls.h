/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:05:32 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/26 16:12:38 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include "libft/libft.h"
# include <sys/stat.h>

typedef struct	s_ls_list
{
	t_list		*error;
	t_list		*files;
	t_list		*folders;
	char		print;
}				t_ls_list;

typedef struct	s_ls_info
{
	char			*name;
	DIR				*dir;
	struct stat		stat;
	struct dirent	*data;
	char            *path;
	t_list          *files;
}				t_ls_info;

int				get_param(int ac, char **av, char (*option)[128]);
void			ft_ls(int ac, char **av, int i, char (*option)[128]);
void			ls_wrapper(char (*option)[128], t_ls_list *start);
void			ls_del_dir(void *content, size_t size);
void			ls_display(char (*option)[128], t_ls_list *start);
void			*ls_set_display(char (*option)[128]);
void			*ls_set_sort(char (*option)[128]);
void			ls_init_list(t_ls_list *start, int ac, char **av, int i,
		char (*option)[128]);
int				ls_sort_name(t_list *prev, t_list *new);
void			ls_display_files(t_ls_list *start, char (*option)[128]);
void			ls_display_error(t_ls_list *start);
void			ls_display_folders(char (*option)[128], t_ls_list *start);

#endif
