/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:05:11 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/21 17:54:26 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
