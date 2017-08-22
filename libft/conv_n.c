/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 09:19:41 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 09:41:09 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_n(t_flags *meta, va_list *ap)
{
	int *i;

	(void)meta;
	i = (int*)va_arg(*ap, int*);
	*i = fill_buffer_str(NULL);
}
