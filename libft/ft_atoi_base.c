/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:54:08 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/11 12:25:48 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check_base(const char *base)
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

int				ft_atoi_base(char *str, const char *base)
{
	int		n;
	int		len_base;

	n = -1;
	if (!str || !base || !check_base(base))
		return (0);
	while (str[++n])
		if (!ft_strchr(base, str[n]))
			return (0);
	n = 0;
	len_base = ft_strlen(base);
	while (*str)
		n = (n * len_base) + (ft_strchr(base, *str++) - base);
	return (n);
}
