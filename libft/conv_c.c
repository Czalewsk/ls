/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:49:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/14 13:00:12 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*char_to_str(int c)
{
	char	*str;

	str = ft_strnew(1);
	*str = c;
	return (str);
}

static	char	*ret_char(t_flags *meta, va_list *ap)
{
	int			c;
	char		*res;

	c = va_arg(*ap, int);
	if (c && (meta->conv == 'C' || meta->lengh == 4))
		res = wchar_to_wstr(c);
	else
		res = char_to_str(c);
	return (res);
}

void			conv_c(t_flags *meta, va_list *ap)
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	len = 1;
	res = ret_char(meta, ap);
	if (!(len = ft_strlen(res)))
		len = 1;
	if (meta->mtag == 1)
	{
		meta->mini_w -= len;
		while (i < len)
			fill_buffer_char(res[i++]);
		len -= i;
		i = 0;
	}
	if (len < meta->mini_w)
		apply_mini_width(&res, meta->mini_w, len);
	if (meta->ztag == 1)
		apply_ztag(&res);
	while (i < len || i < meta->mini_w || res[i])
		fill_buffer_char(res[i++]);
	ft_strdel(&res);
}
