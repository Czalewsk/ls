/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:04:52 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/07 17:44:53 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_param(int ac, char **av, char (*option)[128])
{
	static int		i;

	if (!option || !av)
		return (i);
	while (++i < ac)
	{
		if (av[i][0] != '-' || !av[i][1] || (!ft_strcmp(av[i], "--") && (++i)))
			break ;
		while (*++(av[i]))
			(*option)[(int)(*av[i])] = 1;
	}
	return (i);
}
