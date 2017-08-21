/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:08:53 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/21 20:22:01 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_sort_insert(t_list *prev, t_list *new)
{
	if (ft_strcmp(((struct dirent*)prev->content)->d_name,
				((struct dirent*)new->content)->d_name) < 0)
		return (1);
	return (0);
}

void	ft_ls(int ac, char **av, int i, char (*option)[128])
{
	void			*dir;
	struct	dirent	*data;
	t_list			*start;
	t_list			*tmp;

	(void)option;
	while (i < ac)
	{
		start = NULL;
		dir = opendir(i == ac ? "." : av[i]);
		if (!dir)
			printf("Fichier ou dossier inexistant\n");
		while ((data = readdir(dir)))
			ft_lstinsert_if_end(&start,
					ft_lstnew(data, sizeof(struct dirent)), &ls_sort_insert);
		closedir(dir);
		tmp = start;
		while (tmp)
		{
			printf("%s\n", ((struct dirent*)(tmp->content))->d_name);
			tmp = tmp->next;
		}
		i++;
	}
}

