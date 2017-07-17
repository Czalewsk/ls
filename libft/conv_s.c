/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:08:37 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 05:13:19 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		precision_w_wchar(int *wchar, int prcs)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (wchar[i])
	{
		if (wchar[i] < 0)
			return (0);
		else if (wchar[i] < 0x80)
			len++;
		else if (wchar[i] < 0x800)
			len += 2;
		else if (wchar[i] < 0x10000)
			len += 3;
		else if (wchar[i] < 0x10FFFF)
			len += 4;
		if (len > prcs)
			return (i);
		i++;
	}
	return (i);
}

char			*conv_wstr(va_list *ap, t_flags *meta)
{
	int		*wstr;
	char	*str;

	wstr = va_arg(*ap, void*);
	if (!wstr)
		return (ft_strdup("(null)"));
	wstr = ft_memdup(wstr, (ft_wstrlen(wstr) + 1) * sizeof(int));
	if (meta->prcs > 0 && meta->prcs <= (int)ft_strlen_utf(wstr))
		*(wstr + precision_w_wchar(wstr, meta->prcs)) = 0;
	str = wstr_to_str(wstr);
	ft_memdel((void**)&wstr);
	return (str);
}

void			conv_s(t_flags *meta, va_list *ap)
{
	char		*str;
	int			len;

	if (meta->prcs == 0)
		str = ft_strsub(va_arg(*ap, void*), 0, 0);
	else if (meta->conv == 'S' || meta->lengh == 4)
		str = conv_wstr(ap, meta);
	else
	{
		str = ft_strdup((char*)va_arg(*ap, void*));
		if (!str)
			str = ft_strdup("(null)");
		if (meta->prcs > 0 && meta->prcs < (int)ft_strlen(str))
			str[meta->prcs] = '\0';
	}
	if (meta->mini_w > 0 && (len = (int)ft_strlen(str)) < meta->mini_w)
		apply_mini_width(&str, meta->mini_w, len);
	if (meta->mtag == 1)
		apply_mtag(&str, len > meta->mini_w ? len : meta->mini_w);
	if (meta->ztag == 1)
		apply_ztag(&str);
	fill_buffer_str(str);
	ft_strdel(&str);
}
