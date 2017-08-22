/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bigendian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:53:33 by lduval            #+#    #+#             */
/*   Updated: 2017/05/23 13:55:37 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_bigendian(unsigned char *array, int nb_octet)
{
	unsigned int	j;
	int				i;

	i = 0;
	j = 0;
	while (i < nb_octet)
	{
		j = (j << 8) + array[i];
		i++;
	}
	return (j);
}
