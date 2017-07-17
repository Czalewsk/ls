/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:48:56 by czalewsk          #+#    #+#             */
/*   Updated: 2017/03/23 22:48:05 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H

# define __ARRAY_H

# include "./libft.h"

typedef struct	s_array
{
	size_t		capacity;
	size_t		size;
	size_t		size_type;
	void		**content;
}				t_array;

t_array			*ft_array_new(size_t size, size_t size_type);
void			ft_array_realloc(t_array **array);
void			ft_array_del_elmt(t_array *array, size_t index,
			void (*del)(void **));
void			ft_array_add(t_array *array, void **elmt);
void			ft_array_del(t_array **array, void (*del)(void**));
void			ft_array_iter(t_array *array, void (*f)(void *));

#endif
