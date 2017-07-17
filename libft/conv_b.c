/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 09:09:34 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 09:15:24 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_binary_int(unsigned int nb)
{
	int		n;
	char	*binary;
	int		i;

	i = 0;
	n = (sizeof(unsigned int) * 8);
	binary = ft_strnew(n);
	while (i < n)
	{
		if ((nb >> i) & 1)
			binary[n - 1 - (i++)] = '1';
		else
			binary[n - 1 - (i++)] = '0';
	}
	fill_buffer_str(binary);
}

static	void	print_binary_long(uintmax_t nb)
{
	int		n;
	char	*binary;
	int		i;

	i = 0;
	n = (sizeof(uintmax_t) * 8);
	binary = ft_strnew(n);
	while (i < n)
	{
		if ((nb >> i) & 1)
			binary[n - 1 - (i++)] = '1';
		else
			binary[n - 1 - (i++)] = '0';
	}
	fill_buffer_str(binary);
}

void			conv_b(t_flags *meta, va_list *ap)
{
	if (!meta->lengh || meta->lengh == 3 || meta->lengh == 5)
		print_binary_int((unsigned int)va_arg(*ap, int));
	else
		print_binary_long((uintmax_t)va_arg(*ap, uintmax_t));
}
