/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 05:23:31 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 06:52:04 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_invalid(const char *format, t_flags *meta, int *i)
{
	if (meta->mtag == 1)
		fill_buffer_char(format[(*i)]);
	while (meta->ztag != 1 && --meta->mini_w > 0)
		fill_buffer_char(' ');
	while (meta->ztag == 1 && --meta->mini_w > 0)
		fill_buffer_char('0');
	if (meta->mtag != 1 && meta->conv != 0)
		fill_buffer_char(format[(*i)]);
	else if (meta->mtag != 1)
		(*i)--;
}
