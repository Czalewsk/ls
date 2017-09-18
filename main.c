/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:05:11 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/18 16:15:48 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const	char	g_options[] = "lRart1";

void	print_usage(void)
{
	ft_printf("usage: ls [-%s] [file ...]\n", g_options);
}

int		illegal_option(char (*option)[128], char *name)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		if ((*option)[i] && !ft_strchr(g_options, (char)i))
		{
			ft_printf("%s: illegal option -- %c\n", name + 2, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_option(int ac, char **av, char (*option)[128])
{
	int		i;

	i = get_param(ac, av, option);
	if (!illegal_option(option, av[0]))
	{
		i = -1;
		print_usage();
	}
	return (i);
}

int		main(int ac, char **av)
{
	char			option[128];
	int				i;

	ft_bzero(option, sizeof(option));
	if ((i = check_option(ac, av, &option)) == -1)
		return (0);
	ft_ls(ac, av, &option);
	return (1);
}
