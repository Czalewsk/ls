/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 06:29:38 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:08:06 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_prcs(char **nbr, int prcs)
{
	int		digit;

	digit = ft_count_digit(*nbr);
	if (digit < prcs && (*nbr)[0] != '-' && (*nbr)[0] != '+')
		*nbr = ft_strjoin_free(fill_zero(prcs - digit), 1, *nbr, 1);
	else if (digit < prcs && ((*nbr)[0] == '-' || (*nbr)[0] == '+'))
	{
		*nbr = ft_strjoin_free(fill_zero(prcs - digit), 1, *nbr, 1);
		(*nbr)[0] = (*nbr)[prcs - digit];
		(*nbr)[prcs - digit] = '0';
	}
}
