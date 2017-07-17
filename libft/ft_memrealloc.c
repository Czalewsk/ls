/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:41:28 by czalewsk          #+#    #+#             */
/*   Updated: 2016/12/01 16:47:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrealloc(void *addr, size_t old_size, size_t new_size)
{
	void	*newaddr;

	if (new_size < old_size)
		return (addr);
	newaddr = ft_memalloc(new_size);
	if (!(addr))
		return (newaddr);
	ft_memmove(newaddr, addr, old_size);
	free(addr);
	return (newaddr);
}
