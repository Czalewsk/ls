/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:05:32 by czalewsk          #+#    #+#             */
/*   Updated: 2017/08/21 20:03:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "libft/libft.h"

int		get_param(int ac, char **av, char (*option)[128]);
void	ft_ls(int ac, char **av, int i, char (*option)[128]);

#endif