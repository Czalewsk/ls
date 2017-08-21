/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:05:11 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/21 20:26:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const	char	options[] = "a";

void	print_usage(void)
{
	ft_printf("usage: ls [-%s] [file ...]\n", options);
}

int		illegal_option(char (*option)[128], char *name)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		if ((*option)[i] && !ft_strchr(options, (char)i))
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
	ft_ls(ac, av, i, &option);
	return (1);
}

/*
void		check_option(char (*option)[128])
{
	int		i;

	i = 0;
	while (i < 128)
	{
		if ((*option)[i])
			ft_printf("option %c is set\n", i);
		i++;
	}
}

int		ls_sort_insert(t_list *prev, t_list *new)
{
	if (ft_strcmp(((struct dirent*)prev->content)->d_name, ((struct dirent*)new->content)->d_name))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	void			*dir;
	struct	dirent	*data;
	t_list			*start;
	t_list			*tmp;
	char			option[128];
	int				i;

	i = 0;
	ft_bzero(option, sizeof(option));
	start = NULL;
	i = get_param(ac, av, &option);
	check_option(&option);
	dir = opendir(i == ac ? "." : av[i]);
	if (!dir)
		return(printf("Fichier ou dossier inexistant\n"));
	while ((data = readdir(dir)))
	{
		ft_lstinsert_if_end(&start, ft_lstnew(data, sizeof(struct dirent)), &ls_sort_insert);
	}
	closedir(dir);
	tmp = start;
	while (tmp)
	{
		printf("%s\n", ((struct dirent*)(tmp->content))->d_name);
		tmp = tmp->next;
	}
	return (0);
}

*/

