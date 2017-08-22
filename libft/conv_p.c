/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:15:26 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 05:17:48 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_p(t_flags *meta, va_list *ap)
{
	char		*addr;
	uintmax_t	addr_dec;
	int			len;

	addr_dec = (uintmax_t)va_arg(*ap, void*);
	if (meta->prcs == 0)
		addr = ft_strnew(0);
	else
		addr = ft_itoa_base(addr_dec, "0123456789abcdef");
	len = ft_strlen(addr);
	if (meta->prcs > len)
		addr = ft_strjoin_free(fill_zero(meta->prcs - len), 1, addr, 1);
	addr = ft_strjoin_free("0x", 0, addr, 1);
	len += 2;
	if (len < meta->mini_w)
		apply_mini_width(&addr, meta->mini_w, len);
	if (meta->ztag == 1)
		apply_ztag(&addr);
	if (meta->mtag == 1)
		apply_mtag(&addr, len > meta->mini_w ? len : meta->mini_w);
	fill_buffer_str(addr);
	ft_strdel(&addr);
}
