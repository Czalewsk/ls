/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:44:43 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:40:52 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_pourcent(t_flags *meta, va_list *ap)
{
	int		i;

	(void)ap;
	i = 1;
	if (meta->mtag == 1)
		fill_buffer_char('%');
	if (meta->mini_w - 1 > 0 && meta->ztag == 1 && meta->mtag != 1)
		while (i++ < meta->mini_w)
			fill_buffer_char('0');
	if (meta->mini_w - 1 > 0)
		while (i++ < meta->mini_w)
			fill_buffer_char(' ');
	if (meta->mtag != 1)
		fill_buffer_char('%');
}
