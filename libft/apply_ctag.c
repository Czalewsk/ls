/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ctag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 08:33:49 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:36:12 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		how_many_digit(char *nbr)
{
	int		digit;
	int		i;

	i = -1;
	digit = 0;
	while (nbr[++i])
		if (ft_isdigit(nbr[i]))
			digit++;
	return (digit);
}

static	void	ctag_function(char **str)
{
	int		i;
	int		digit;
	char	*new;
	int		len;

	i = -1;
	len = ft_strlen(*str);
	digit = how_many_digit(*str);
	if (digit < 4)
		return ;
	i = 0;
	while ((*str)[i] && (*str)[i] == 32)
		i++;
	i = (i > (digit - 1) / 3) ? len : len + ((digit - 1) / 3) - i;
	new = ft_strnew(i);
	digit = 0;
	while (i >= 0)
	{
		if (!(digit % 4) && ft_isdigit((*str)[len]) && (new[i--] = SPR))
			digit = 1;
		else if (digit += 1)
			new[i--] = (*str)[len--];
	}
	free(*str);
	*str = new;
}

void			apply_ctag(t_flags *meta, char **str)
{
	if (meta->ctag != 1)
		return ;
	ctag_function(str);
}
