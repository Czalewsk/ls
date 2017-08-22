/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:51:28 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/14 13:06:41 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	uintmax_t	len_caster(t_flags *meta, va_list *ap)
{
	uintmax_t		nb;

	if (!meta->lengh && meta->conv == 'o')
		nb = (unsigned int)va_arg(*ap, int);
	else if (meta->lengh == 3 && meta->conv != 'O')
		nb = (unsigned short)va_arg(*ap, int);
	else if (meta->lengh == 5 && meta->conv != 'O')
		nb = (unsigned char)va_arg(*ap, int);
	else
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	return (nb);
}

void				conv_o(t_flags *meta, va_list *ap)
{
	uintmax_t		nb;
	char			*octal;
	int				len;

	nb = len_caster(meta, ap);
	if (meta->prcs == 0 && nb == 0)
		octal = ft_strnew(0);
	else
		octal = ft_itoa_base((uintmax_t)nb, "01234567");
	len = ft_strlen(octal);
	if (meta->prcs > 0 && meta->prcs > len)
		octal = ft_strjoin_free(fill_zero(meta->prcs - len), 1, octal, 1);
	if (meta->htag && (meta->prcs != -1 || nb != 0) && octal[0] != '0')
		octal = ft_strjoin_free("0", 0, octal, 1);
	len = ft_strlen(octal);
	if (meta->mini_w > len)
		apply_mini_width(&octal, meta->mini_w, len);
	if (meta->mtag == 1)
		apply_mtag(&octal, ft_strlen(octal));
	if (meta->ztag == 1 && meta->mtag != 1 && meta->prcs <= 0)
		apply_ztag(&octal);
	fill_buffer_str(octal);
	ft_strdel(&octal);
}
