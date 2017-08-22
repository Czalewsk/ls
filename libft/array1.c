/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:03:25 by czalewsk          #+#    #+#             */
/*   Updated: 2017/03/23 22:48:48 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void		ft_array_iter(t_array *array, void (*f)(void *))
{
	size_t		i;

	i = 0;
	if (!array || !f)
		return ;
	while (i < array->size)
		f(array->content + i++);
}
