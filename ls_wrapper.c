/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:36:01 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/24 10:30:38 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_wrapper(char (*option)[128], t_ls_list *start)
{
	ls_display_error(start);
	ls_display_files(start, option);
	ls_display_folders(option, start);
	return ;
}