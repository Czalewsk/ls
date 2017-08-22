/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:21:45 by xesnault          #+#    #+#             */
/*   Updated: 2017/05/23 13:56:01 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_filename(char *path)
{
	char	*tmp;
	char	*filename;

	if ((tmp = ft_strrchr(path, '/')) && *(tmp + 1))
		filename = ft_strdup(tmp + 1);
	else
		filename = ft_strdup(path);
	return (filename);
}

static char		*get_path_without_filename(char *path)
{
	char	*tmp;
	char	*path_wfn;

	path_wfn = NULL;
	if (!path || !(path_wfn = ft_strdup(path)))
		return (NULL);
	if ((tmp = ft_strrchr(path_wfn, '/')) && *(tmp + 1))
		*(tmp + 1) = 0;
	else
		path_wfn[0] = 0;
	return (path_wfn);
}

char			*ft_cfextension(char *filename, char *extension)
{
	char	*old_filename;
	char	*new_filename;
	char	*path_wfn;
	char	*tmp;

	if (!extension || !filename || !(old_filename = get_filename(filename)))
		return (NULL);
	if (!(new_filename = ft_strnew(ft_strlen(filename)
		+ ft_strlen(extension) + 2)))
		return (NULL);
	if (!(path_wfn = get_path_without_filename(filename)))
		return (NULL);
	tmp = ft_strrchr(old_filename, '.');
	if (tmp)
		*tmp = 0;
	if (path_wfn)
		ft_strcpy(new_filename, path_wfn);
	ft_strcat(new_filename, old_filename);
	ft_strcat(new_filename, extension);
	free(old_filename);
	free(path_wfn);
	return (new_filename);
}
