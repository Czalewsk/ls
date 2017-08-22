/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:47:08 by czalewsk          #+#    #+#             */
/*   Updated: 2017/03/23 22:48:37 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_array_new(size_t capacity, size_t size_type)
{
	t_array		*array;

	if (!(array = ft_memalloc(sizeof(t_array))))
		return (NULL);
	if (!(array->content = ft_memalloc(capacity * size_type)))
		return (NULL);
	array->size_type = size_type;
	array->capacity = capacity;
	array->size = 0;
	return (array);
}

void		ft_array_realloc(t_array **array)
{
	size_t		old_capacity;

	if ((*array)->capacity <= 0)
		return ;
	old_capacity = (*array)->capacity * (*array)->size_type;
	if (!((*array)->content = ft_memrealloc((*array)->content,
					old_capacity, old_capacity * 2)))
		return ;
	(*array)->capacity *= 2;
}

void		ft_array_add(t_array *array, void **elmt)
{
	void *cp_elmt;

	if (array->size + 1 >= array->capacity)
		ft_array_realloc(&array);
	cp_elmt = (array->content + array->size);
	cp_elmt = ft_memcpy(cp_elmt, elmt, array->size_type);
	array->size++;
}

void		ft_array_del_elmt(t_array *array, size_t index,
		void (*del)(void **))
{
	void **elmt;

	elmt = (array->content + index);
	if (index > array->size)
		return ;
	if (del)
		del(elmt);
	if (index < array->size)
		ft_memmove(elmt, elmt + 1, array->size_type * (array->size - index));
	ft_bzero(array->content + array->size, array->size_type);
	array->size--;
}

void		ft_array_del(t_array **array, void (*del)(void **))
{
	size_t		i;

	i = 0;
	while (i < (*array)->size && del)
		del((*array)->content + i++);
	ft_memdel((void**)&(*array)->content);
	ft_memdel((void**)array);
}
