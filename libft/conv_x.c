/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:13:31 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 07:41:16 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		*htag_apply(t_flags *meta, int nb, char *hexa)
{
	if (nb != 0 && meta->htag)
	{
		if (meta->conv == 'x')
			hexa = ft_strjoin_free("0x", 0, hexa, 1);
		else
			hexa = ft_strjoin_free("0X", 0, hexa, 1);
	}
	return (hexa);
}

static	uintmax_t	len_caster(t_flags *meta, va_list *ap)
{
	uintmax_t		nb;

	if (!meta->lengh)
		nb = (unsigned int)va_arg(*ap, int);
	else if (meta->lengh == 3)
		nb = (unsigned short)va_arg(*ap, int);
	else if (meta->lengh == 5)
		nb = (unsigned char)va_arg(*ap, int);
	else
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	return (nb);
}

void				conv_x(t_flags *meta, va_list *ap)
{
	uintmax_t		nb;
	char			*hexa;
	int				len;

	nb = len_caster(meta, ap);
	if (meta->prcs == 0 && nb == 0)
		hexa = ft_strnew(0);
	else if (meta->conv == 'x')
		hexa = ft_itoa_base((uintmax_t)nb, "0123456789abcdef");
	else
		hexa = ft_itoa_base((uintmax_t)nb, "0123456789ABCDEF");
	len = ft_strlen(hexa);
	if ((nb != 0 || meta->prcs != 0) && meta->prcs > len)
		hexa = ft_strjoin_free(fill_zero(meta->prcs - len), 1, hexa, 1);
	hexa = htag_apply(meta, nb, hexa);
	len = ft_strlen(hexa);
	if (meta->mini_w > len)
		apply_mini_width(&hexa, meta->mini_w, len);
	if (meta->ztag == 1 && meta->mtag == 0)
		apply_ztag(&hexa);
	if (meta->mtag == 1)
		apply_mtag(&hexa, ft_strlen(hexa));
	fill_buffer_str(hexa);
	ft_strdel(&hexa);
}
