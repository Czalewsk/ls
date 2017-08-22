/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:38:08 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 06:17:14 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_mini_width(char **str, int w, int len)
{
	int		i;

	i = 0;
	*str = ft_memrealloc(*str, len, w + 1);
	ft_memmove((*str) - len + w, *str, len);
	while (i < w - len)
		(*str)[i++] = ' ';
}
