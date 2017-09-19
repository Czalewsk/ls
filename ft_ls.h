/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:05:32 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/19 10:28:51 by czalewsk         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <errno.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>

typedef struct	s_ls_list
{
	t_list		*error;
	t_list		*files;
	t_list		*folders;
	char		print;
}				t_ls_list;

typedef struct	s_ls_ln
{
	char			perms[12];
	unsigned long	size;
	unsigned long	link;
	char			time[14];
	char			*owner;
	char			*group;
}				t_ls_ln;

typedef struct	s_ls_info
{
	char			*name;
	DIR				*dir;
	char			*path;
	struct stat		stat;
	char			err;
	char			is_folder;
	int				deep;
	int				is_display;
	t_ls_ln			*line;
}				t_ls_info;

typedef struct	s_ls_col
{
	int				col;
	int				entry;
	int				max_entry;
	int				max_len;
	int				size_line;
	int				nb_line;
}				t_ls_col;

typedef struct	s_ls_ext
{
	unsigned long	total;
	int				name;
	int				link;
	int				user;
	int				group;
	int				size;
	int				maj_min;
}				t_ls_ext;

typedef struct	s_ls_entry
{
	int				type;
	char			match;
	int				maj_min;
}				t_ls_entry;

int				get_param(int ac, char **av, char (*option)[128]);
void			ft_ls(int ac, char **av, char (*option)[128]);
void			ls_wrapper(char (*option)[128], t_ls_list *start);
void			ls_del_files(void *content, size_t size);
void			ls_del_folders(void *content, size_t size);
void			ls_display(char (*option)[128], t_ls_list *start);
void			*ls_set_display(char (*option)[128]);
void			*ls_set_sort(char (*option)[128]);
void			ls_init_list(t_ls_list *start, int ac, char **av,
		char (*option)[128]);
int				ls_sort_name(t_list *prev, t_list *new);
void			ls_display_files(t_ls_list *start, char (*option)[128],
		t_ls_info *file);
void			ls_display_error(t_ls_list *start);
void			ls_display_folders(char (*option)[128], t_ls_list *start);
int				ls_get_col(void);
int				ls_get_longer(t_list *files, char dot_files);
int				ls_format_col(t_ls_list *start, char dot_files, t_list *files,
		t_ls_col *col);
int				ls_check_perm_x(t_ls_info *file, char dot_files);
void			ls_display_col(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start);
void			ls_create_ln(t_ls_info *file, t_ls_ext *info, t_ls_ln *new,
		time_t *actual);
void			ls_display_ext(t_ls_info *file, char dot_files, t_list *files,
		t_ls_list *start);
void			ls_format_line_m(char *line, t_ls_ext *info, t_ls_info *file);
void			ls_format_line_n(char *line, t_ls_ext *info, t_ls_info *file);

#endif
