/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_utf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:33:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/11 13:34:46 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_utf(const int *str)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 0)
			return (0);
		else if (str[i] < 0x80)
			len++;
		else if (str[i] < 0x800)
			len += 2;
		else if (str[i] < 0x10000)
			len += 3;
		else if (str[i] < 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}
