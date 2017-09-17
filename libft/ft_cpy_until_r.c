/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_until_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 06:23:46 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/17 18:06:29 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cpy_until_r(char *s, const char *cpy, char c, int n)
{
	int		len_s;
	int		len_cpy;
	int		i;

	i = -1;
	len_s = ft_strlen(s);
	len_cpy = ft_strlen(cpy);
	*(s + len_s + n) = '\0';
	while (++i < n - len_cpy)
		*(s + len_s + i) = c;
	while (--len_cpy >= 0)
		*(s + len_s + i + len_cpy) = *(cpy + len_cpy);
	return (s);
}
