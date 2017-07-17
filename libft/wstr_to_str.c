/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:32:39 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/11 14:41:04 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	wchar_to_char(int wchar, char **str)
{
	int					n;
	unsigned	int		msk;
	int					i;

	msk = 1;
	n = 2;
	while ((wchar >> (7 + (n * 4 + n / 2))) == 0)
		n--;
	n += 2;
	i = n;
	while (i-- > 1)
		msk = (msk << 1) + 1;
	*(*str)++ = ((wchar >> (6 * (n - 1))) + (msk << (8 - n)));
	while (--n > 0)
		*(*str)++ = ((wchar >> ((n - 1) * 6)) & 0x3F) + 0x80;
}

char			*wstr_to_str(int *wstr)
{
	char	*str;
	char	*curs;
	int		len;

	if (!wstr)
		return (NULL);
	len = ft_strlen_utf(wstr);
	str = ft_strnew(len);
	curs = str;
	while (*wstr)
	{
		if (*wstr < 0x80)
			*curs++ = *wstr;
		else if (*wstr < 0x10FFFF)
			wchar_to_char(*wstr, &curs);
		else
			return (NULL);
		wstr++;
	}
	return (str);
}

char			*wchar_to_wstr(int wchar)
{
	int		i[2];

	i[0] = wchar;
	i[1] = 0;
	return (wstr_to_str(i));
}
