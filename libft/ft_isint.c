/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 09:15:40 by czalewsk          #+#    #+#             */
/*   Updated: 2017/04/25 08:39:38 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *nb)
{
	long int	nbr;
	int			n;
	int			nb_len;
	int			i;

	i = 0;
	n = 0;
	nb_len = 0;
	while (*nb == ' ')
		nb++;
	if (nb[n] == '+' || nb[n] == '-')
		n++;
	while (nb[n + i] && nb[n + i] == 48)
		++i;
	while (nb[n + i + nb_len] && ft_isdigit(nb[nb_len + n + i]))
		nb_len++;
	if (nb_len > 10)
		return (0);
	while (nb[n])
		if (!ft_isdigit(nb[n++]))
			return (0);
	nbr = ft_atol(nb);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return ((nb_len + i) > 0 ? 1 : 0);
}
/*
**	intmax_t	nbr;
**	int			i;
**	char		*nb_cp;
**	int			len;
**
**	len = 0;
**	i = 0;
**	while (nb[i] && nb[i] == ' ')
**		i++;
**	if (nb[i] == '+')
**		i++;
**	else if (nb[i] == '-' && ft_isdigit(nb[i + 1]))
**		len++;
**	while (nb[i + len] && ft_isdigit(nb[i + len]))
**		len++;
**	if (len == 0)
**		return (0);
**	nbr = ft_atoi(nb + i);
**	nb_cp = ft_itoa((int)nbr);
**	if (!ft_strncmp(nb + i, nb_cp, len))
**		i = -1;
**	else
**		i = -2;
**	ft_strdel(&nb_cp);
**	return ((i == -1) ? 1 : 0);
*/
