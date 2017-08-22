/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:45:25 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/11 12:26:21 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			check_base(const char *base)
{
	int		i;
	int		n;

	i = 0;
	while (base[i])
	{
		if (!ft_isalnum(base[i]))
			return (0);
		n = -1;
		while (base[++n])
			if (n != i && base[n] == base[i])
				return (0);
		i++;
	}
	return (1);
}

static	int			len_in_base(uintmax_t nb, int base)
{
	int		len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return ((len == 0) ? 1 : len);
}

char				*ft_itoa_base(uintmax_t n, const char *base)
{
	int		len;
	char	*nb;
	int		i;

	if (!base || !check_base(base))
		return (NULL);
	len = ft_strlen(base);
	if (len < 2)
		return (NULL);
	i = len_in_base(n, len);
	nb = ft_strnew(i);
	while (i > 0)
	{
		nb[--i] = base[n % len];
		n /= len;
	}
	return (nb);
}
