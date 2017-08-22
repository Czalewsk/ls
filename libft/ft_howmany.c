/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_howmany.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:08:31 by czalewsk          #+#    #+#             */
/*   Updated: 2017/02/05 17:10:14 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_howmany(char *line, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!line)
		return (0);
	while (line[i])
		if (line[i++] == c)
			n++;
	return (n);
}
