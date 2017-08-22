/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ptag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 05:42:33 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 08:02:43 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			apply_ptag(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i] && (*str)[i] == ' ')
		i++;
	if ((*str)[i] == '-')
		return ;
	else if (ft_count_digit(*str) > 1 && (*str)[i] == '0')
		(*str)[i] = '+';
	else if (i > 1 && ft_count_digit(*str) > 1)
		(*str)[i - 1] = '+';
	else
		(*str) = ft_strjoin_free("+", 0, *str, 1);
}
