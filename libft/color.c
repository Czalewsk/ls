/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:46:52 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/05 13:08:58 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_to_color[] = {"black", "red", "green", "yellow", "blue", "pink",
	"cyan", "white", NULL};

char	*g_spec[] = {
	"G\033[1m",
	"e\033[0m",
	"I\033[3m",
	"U\033[4m",
	"O\033[7m",
	0
};

static	void	print_color(char *code)
{
	int		i;
	char	*c;

	i = -1;
	while (g_spec[++i])
		if (g_spec[i][0] == *code)
			fill_buffer_str(&g_spec[i][1]);
	i = -1;
	if (*code == 'n')
		return ;
	while (g_to_color[++i])
		if (ft_strcmp(code, g_to_color[i]) == '}')
		{
			c = ft_itoa(30 + i);
			fill_buffer_str("\033[");
			fill_buffer_str(c);
			fill_buffer_str("m");
			ft_strdel(&c);
		}
	return ;
}

void			color(const char *format, int *i)
{
	char	*code;
	int		n;

	n = *i;
	if (format[++(*i)] == '{')
	{
		fill_buffer_char('{');
		return ;
	}
	while (format[(*i)] && format[(*i)] != '}')
		(*i)++;
	code = ft_strsub(format, n + 1, (*i) - n);
	print_color(code);
	free(code);
}
