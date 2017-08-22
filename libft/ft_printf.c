/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:55:30 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/30 07:40:45 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int		g_ret;
extern int		g_i;
extern char		*g_buffer;

static	void	switcher(const char *format, va_list *ap, int *i)
{
	t_flags		*meta;
	void		(*fct)();

	fct = NULL;
	if ((meta = fill_struct(format, ap, i)))
		fct = is_option(meta->conv);
	if (fct)
		fct(meta, ap);
	else
		conv_invalid(format, meta, i);
	free(meta);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	int			ret;

	g_fct = ft_strdup("sSpdDioOuUxXcC%bn");
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '{')
			color(format, &i);
		else if (format[i] != '%')
			fill_buffer_char(format[i]);
		else
			switcher(format, &ap, &i);
		i++;
	}
	va_end(ap);
	ft_strdel(&g_fct);
	ret = fill_buffer_str(NULL);
	g_ret = 0;
	return (ret);
}
