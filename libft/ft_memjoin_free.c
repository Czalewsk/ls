/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:01:23 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/30 19:10:33 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin_free(void *addr1, size_t size1, void *addr2, size_t size2)
{
	void	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size1 + size2 == 0)
		return (NULL);
	new = ft_memalloc(size1 + size2);
	while (i < size1)
	{
		((UC*)new)[i] = ((UC*)addr1)[i];
		i++;
	}
	while (j < size2)
	{
		((UC*)new)[i + j] = ((UC*)addr2)[j];
		j++;
	}
	free(addr1);
	return (new);
}
