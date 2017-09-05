/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 08:48:06 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/05 09:09:40 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

int		main(void)
{
	struct winsize	ws;
	unsigned long	i;
	unsigned long	d;

	i = 0;
	d = 3;
	ft_bzero(&ws, sizeof(ws));
	ft_printf("Retour de IOCTL=%d\n", ioctl(1, TIOCGWINSZ, &ws));
	ft_printf("ROW=%lu | COL=%lu\n", ws.ws_row, ws.ws_col);
	while (i++ < ws.ws_col)
		ft_putchar(48 + (i % 10));
	write(1, "\n", 1);
	while(d++ < ws.ws_row)
	{
		ft_putnbr(d);
	write(1, "\n", 1);
	}
}