/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:40:01 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/15 10:33:40 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_wrapper(char (*option)[128], t_ls_list *start)
{
	ls_display_error(start);
	ls_display_files(start, option, NULL);
	ls_display_folders(option, start);
	ft_lstdel(&start->files, &ls_del_folders);
	return ;
}
