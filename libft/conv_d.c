/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:23:15 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:44:35 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	intmax_t	len_caster(t_flags *meta, va_list *ap)
{
	intmax_t		nb;

	if (!meta->lengh && meta->conv != 'D')
		nb = (int)va_arg(*ap, int);
	else if (meta->lengh == 3 && meta->conv != 'D')
		nb = (short)va_arg(*ap, int);
	else if (meta->lengh == 5 && meta->conv != 'D')
		nb = (signed char)va_arg(*ap, int);
	else if (meta->lengh == 2 && meta->conv != 'D')
		nb = (size_t)va_arg(*ap, size_t);
	else
		nb = (intmax_t)va_arg(*ap, uintmax_t);
	return (nb);
}

void				conv_d(t_flags *meta, va_list *ap)
{
	intmax_t		nb;
	char			*nbr;
	int				len;

	nb = len_caster(meta, ap);
	if (meta->prcs == 0 && nb == 0)
		nbr = ft_strnew(0);
	else
		nbr = ft_itoa(nb);
	len = ft_strlen(nbr);
	if (meta->ptag == 1)
		apply_ptag(&nbr);
	apply_prcs(&nbr, meta->prcs);
	if (meta->mini_w > (len = ft_strlen(nbr)))
		apply_mini_width(&nbr, meta->mini_w, len);
	if (meta->ztag == 1 && meta->mtag != 1 && meta->prcs == -1)
		apply_ztag(&nbr);
	if (meta->sptag == 1 && meta->ptag != 1 && !ft_strchr(nbr, '-'))
		apply_sptag(&nbr);
	if (meta->mtag == 1)
		apply_mtag(&nbr, len > meta->mini_w ? len : meta->mini_w);
	apply_ctag(meta, &nbr);
	fill_buffer_str(nbr);
	ft_strdel(&nbr);
}
