/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:43:54 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/07 14:06:02 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_int_len(intmax_t n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (!(n > (-10) && n < 10))
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	int		i;
	char	*nb;

	i = ft_int_len(n);
	if (!(nb = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		nb[0] = '-';
	else
		n *= -1;
	while (i >= 1 && nb[i - 1] != '-')
	{
		nb[--i] = -(n % 10) + 48;
		n /= 10;
	}
	return (nb);
}
