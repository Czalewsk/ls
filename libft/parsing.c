/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:46:20 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 07:26:05 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags		*init_struct(void)
{
	t_flags		*m_flags;

	if (!(m_flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	m_flags->htag = 0;
	m_flags->ztag = 0;
	m_flags->ptag = 0;
	m_flags->mtag = 0;
	m_flags->ctag = 0;
	m_flags->sptag = 0;
	m_flags->mini_w = -1;
	m_flags->prcs = -1;
	m_flags->lengh = 0;
	m_flags->conv = 0;
	return (m_flags);
}

static	int			custom_atoi(const char *nb, int *i)
{
	int		nbr;
	int		s;

	s = 1;
	nbr = 0;
	if (nb[*i] == 45 && ((*i) += 1))
		s = -1;
	while (nb[*i] && ft_isdigit(nb[*i]))
	{
		nbr = (nb[*i] - 48) + (nbr * 10);
		(*i)++;
	}
	(*i)--;
	nbr *= s;
	return (nbr);
}

static	int			is_flag(char c, t_flags *m_flags)
{
	if (c == 32)
		m_flags->sptag = 1;
	else if (c == 35)
		m_flags->htag = 1;
	else if (c == 43)
		m_flags->ptag = 1;
	else if (c == 45)
		m_flags->mtag = 1;
	else if (c == 48)
		m_flags->ztag = 1;
	else if (c == 39)
		m_flags->ctag = 1;
	else
		return (0);
	return (1);
}

static		void	wildcard_bonus(t_flags *m_flags, va_list *ap, int wp)
{
	int		nb;

	nb = va_arg(*ap, int);
	if (wp == 0)
	{
		if (nb < 0)
		{
			nb *= -1;
			m_flags->mtag = 1;
		}
		m_flags->mini_w = nb;
	}
	else
	{
		if (nb < 0)
			nb = -1;
		m_flags->prcs = nb;
	}
}

t_flags				*fill_struct(const char *converts, va_list *ap, int *i)
{
	t_flags		*m_flags;

	m_flags = init_struct();
	while (m_flags && !m_flags->conv && converts[++(*i)])
	{
		if (is_flag(converts[*i], m_flags))
			;
		else if (ft_isdigit(converts[*i]))
			m_flags->mini_w = custom_atoi(converts, i);
		else if (converts[*i] == 42 && converts[(*i) - 1] != 46)
			wildcard_bonus(m_flags, ap, 0);
		else if (converts[*i] == 46 && converts[(*i + 1)] == 42 && ((*i) += 1))
			wildcard_bonus(m_flags, ap, 1);
		else if (converts[*i] == 46 && ((*i) += 1))
			m_flags->prcs = custom_atoi(converts, i);
		else if (converts[*i] == 'j' || converts[*i] == 'z')
			m_flags->lengh = (((converts[*i] >> 4) & 1) + 1);
		else if ((converts[*i] == 'h' || converts[*i] == 'l')
				&& (m_flags->lengh = (((converts[*i] >> 2) & 1) + 3))
					&& (converts[*i] == converts[(*i) + 1]) && ((*i)++))
			m_flags->lengh += 2;
		else if (converts[*i] != 'l' && converts[*i] != 'h')
			m_flags->conv = converts[*i];
	}
	return (m_flags);
}
