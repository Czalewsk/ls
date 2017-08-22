/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:07:12 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/11 19:09:50 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_digit(char *str)
{
	size_t		digit;
	int			i;

	i = -1;
	digit = 0;
	while (str[++i])
		if (ft_isdigit(str[i]))
			digit++;
	return (digit);
}
