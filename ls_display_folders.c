/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_folders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:23:23 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/03 21:56:44 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_display_folders(char (*option)[128], t_ls_list *start)
{
	t_list			*folders;

	(void)option;
	folders = start->folders;
	while (folders)
	{
		ft_printf("\n%s:\n", ((t_ls_info*)folders->content)->name);
		folders = folders->next;
	}
}
