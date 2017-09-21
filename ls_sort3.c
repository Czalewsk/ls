/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:08:21 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/21 17:25:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_sort_time_acc(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_atime >
			((t_ls_info*)(cur->content))->stat.st_atime ? 0 : 1);
}

int			ls_sort_time_acc_r(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_atime <
			((t_ls_info*)(cur->content))->stat.st_atime ? 0 : 1);
}

int			ls_sort_time_crea(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_birthtime >
			((t_ls_info*)(cur->content))->stat.st_birthtime? 0 : 1);
}

int			ls_sort_time_crea_r(t_list *prev, t_list *cur)
{
	return (((t_ls_info*)(prev->content))->stat.st_birthtime <
			((t_ls_info*)(cur->content))->stat.st_birthtime ? 0 : 1);
}
