/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:49:54 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 09:20:21 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	*is_option2(int i, void (**fct)())
{
	*(fct + 12) = &conv_c;
	*(fct + 13) = &conv_c;
	*(fct + 14) = &conv_pourcent;
	*(fct + 15) = &conv_b;
	*(fct + 16) = &conv_n;
	return (*(fct + i));
}

void			*is_option(char c)
{
	void	(**fct)();
	int		i;
	void	(*f)();

	i = 0;
	fct = ft_memalloc(sizeof(*fct) * (ft_strlen(g_fct) + 1));
	*(fct) = &conv_s;
	*(fct + 1) = &conv_s;
	*(fct + 2) = &conv_p;
	*(fct + 3) = &conv_d;
	*(fct + 4) = &conv_d;
	*(fct + 5) = &conv_d;
	*(fct + 6) = &conv_o;
	*(fct + 7) = &conv_o;
	*(fct + 8) = &conv_u;
	*(fct + 9) = &conv_u;
	*(fct + 10) = &conv_x;
	*(fct + 11) = &conv_x;
	while (g_fct[i] && g_fct[i] != c)
		i++;
	f = (i < 12) ? *(fct + i) : (void(*)())is_option2(i, fct);
	f = (g_fct[i] == c) ? f : NULL;
	free(fct);
	return (f);
}
