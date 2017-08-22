/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:00:18 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:17:13 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*g_buffer = NULL;
int g_i = 0;
int g_ret = 0;

static	void	write_and_free(void)
{
	if (!g_i)
		return ;
	write(1, g_buffer, g_i);
	g_ret += g_i;
	ft_strdel(&g_buffer);
	g_i = 0;
}

int				fill_buffer_char(char c)
{
	if (g_i == BUFF_PRINT && g_buffer)
		write_and_free();
	if (!g_buffer)
		g_buffer = ft_strnew(BUFF_PRINT + 1);
	g_buffer[g_i++] = c;
	if (g_i == BUFF_PRINT)
		fill_buffer_char(0);
	return (g_ret);
}

int				fill_buffer_str(char *str)
{
	int				n;

	n = 0;
	if ((g_i == BUFF_PRINT || !str) && g_buffer)
		write_and_free();
	if (!g_buffer && str)
		g_buffer = ft_strnew(BUFF_PRINT + 1);
	if (str)
		while (str[n] && g_i < BUFF_PRINT)
			g_buffer[g_i++] = str[n++];
	if (str && str[n])
		fill_buffer_str(str + n);
	else if (g_i == BUFF_PRINT)
		fill_buffer_str(NULL);
	return (g_ret);
}
