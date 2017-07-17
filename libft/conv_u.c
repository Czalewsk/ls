/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 03:04:50 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:12:35 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	uintmax_t		len_caster(t_flags *meta, va_list *ap)
{
	uintmax_t			nb;

	if (!meta->lengh && meta->conv == 'u')
		nb = (unsigned int)va_arg(*ap, int);
	else if (meta->lengh == 3 && meta->conv != 'U')
		nb = (unsigned short)va_arg(*ap, int);
	else if (meta->lengh == 5 && meta->conv != 'U')
		nb = (unsigned char)va_arg(*ap, int);
	else
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	return (nb);
}

void					conv_u(t_flags *meta, va_list *ap)
{
	uintmax_t		nb;
	char			*nbr;
	int				len;

	nb = len_caster(meta, ap);
	if (meta->prcs == 0 && nb == 0)
		nbr = ft_strnew(0);
	else
		nbr = ft_itoa_u(nb);
	apply_prcs(&nbr, meta->prcs);
	len = ft_strlen(nbr);
	if (meta->mini_w > len)
		apply_mini_width(&nbr, meta->mini_w, len);
	if (meta->mtag == 1)
		apply_mtag(&nbr, ft_strlen(nbr));
	else if (meta->ztag == 1)
		apply_ztag(&nbr);
	fill_buffer_str(nbr);
	ft_strdel(&nbr);
}
