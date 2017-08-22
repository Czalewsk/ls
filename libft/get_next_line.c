/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:58:10 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/09 22:37:15 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rm_content(void *curs, size_t size)
{
	(void)size;
	free(((t_str*)curs)->buff);
	free(curs);
}

int		fill_buffer(int fd, t_str *curs, char **line)
{
	int		t;
	int		i;
	int		ret;

	i = 0;
	t = curs->size;
	if (!ft_memchr(curs->buff, 10, curs->size))
		while ((curs->size = read(fd, curs->buff, BUFF_SIZE)) > 0)
		{
			ret = curs->size;
			*line = ft_memrealloc(*line, t, t + curs->size + 1);
			ft_memmove(*line + t, curs->buff, curs->size);
			t += curs->size;
			if (ft_memchr(curs->buff, 10, curs->size))
				break ;
			if (ret < BUFF_SIZE)
				break ;
		}
	ret = (curs->size == 0) ? t : curs->size;
	while (i < t && (*line)[i] != 10)
		i++;
	(*line)[i] = '\0';
	ft_memmove(curs->buff, *line + i + 1, t - i);
	curs->size = (t - i - 1) >= 0 ? (t - i - 1) : 0;
	return (ret);
}

t_list	*init_struct(t_list **start, int fd)
{
	t_str	*strct;
	t_list	*new;

	strct = (t_str*)ft_memalloc(sizeof(t_str));
	strct->fd = fd;
	strct->buff = (char*)ft_memalloc(BUFF_SIZE);
	strct->size = 0;
	new = ft_lstnew(strct, sizeof(t_str));
	ft_lst_pushend(start, new);
	free(strct);
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*start;
	t_list			*curs;
	int				ret;

	if (fd == -2 && start && !line)
		ft_lstdel(&start, &rm_content);
	if (fd < 0 || !line)
		return (-1);
	curs = start;
	while (curs && CT(curs)->fd != fd)
		curs = curs->next;
	curs = (curs == NULL) ? init_struct(&start, fd) : curs;
	if (CT(curs)->buff && CT(curs)->size >= 0)
	{
		*line = ft_memalloc(CT(curs)->size + 1);
		ft_memmove(*line, CT(curs)->buff, CT(curs)->size);
	}
	ret = fill_buffer(fd, CT(curs), line);
	if (ret <= 0)
	{
		ft_lst_remove(&start, curs, &rm_content);
		return ((ret < 0) ? -1 : 0);
	}
	return (1);
}
