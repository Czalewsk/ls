/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 06:23:46 by czalewsk          #+#    #+#             */
/*   Updated: 2017/09/17 17:53:02 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cpy_until(char *s, const char *cpy, char c, int n)
{
	int		len_s;
	int		i;

	i = -1;
	len_s = ft_strlen(s);
	*(s + len_s + n) = '\0';
	while (*(cpy + ++i))
		*(s + len_s + i) = *(cpy + i);
	while (i < n)
		*(s + len_s + i++) = c;
	return (s);
}
