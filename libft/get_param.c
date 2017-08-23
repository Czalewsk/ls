/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:04:52 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/22 13:05:51 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_param(int ac, char **av, char (*option)[128])
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	if (!option)
		return (0);
	while (++i < ac)
	{
		if (av[i][0] != '-' || !av[i][1] || !ft_strcmp(av[i], "--"))
			break ;
		while (*++(av[i]))
			(*option)[(int)(*av[i])] = 1;
	}
	return (i);
}
