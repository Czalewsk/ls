/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_mtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 04:04:04 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 04:07:00 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_mtag(char **str, int len)
{
	int		i;

	i = 0;
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	if (len == i)
		return ;
	ft_memmove(*str, (*str) + i, len - i);
	i = len - i;
	while (i < len)
		(*str)[i++] = ' ';
}
