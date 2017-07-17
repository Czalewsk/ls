/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:03:45 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/11 19:06:16 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*fill_zero(int n)
{
	char		*str;
	int			i;

	if (n <= 0)
		return (ft_strnew(0));
	i = 0;
	str = ft_strnew(n);
	while (i < n)
		str[i++] = '0';
	return (str);
}
