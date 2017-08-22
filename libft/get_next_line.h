/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:52:40 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/14 14:14:21 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft.h"
# include <stdio.h>

# define BUFF_SIZE 500
# define CT(Pointeur) ((t_str*)(Pointeur->content))

typedef	struct		s_str
{
	int			fd;
	char		*buff;
	int			size;
}					t_str;

int					get_next_line(const int fd, char **line);
#endif
