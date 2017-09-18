/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:17:37 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/18 17:53:06 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!(mem = malloc(size)))
	{
		ft_putendl_fd("Fail to malloc\n Hint : Buy a real pc :D", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(mem, size);
	return (mem);
}
