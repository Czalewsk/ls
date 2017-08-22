/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:50:45 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/30 07:40:39 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define BUFF_PRINT 500
# define SPR '.'

char				*g_fct;

typedef struct		s_flags
{
	int				htag;
	int				ztag;
	int				ptag;
	int				mtag;
	int				ctag;
	int				sptag;
	int				mini_w;
	int				prcs;
	int				lengh;
	char			conv;
}					t_flags;

int					ft_printf(const char *format, ...);
int					fill_buffer_char(char c);
int					fill_buffer_str(char *str);
void				*is_option(char c);
t_flags				*fill_struct(const char *format, va_list *ap, int *i);
char				*wstr_to_str(int *wstr);
void				conv_s(t_flags *meta, va_list *ap);
void				conv_p(t_flags *meta, va_list *ap);
void				apply_mini_width(char **str, int w, int len);
void				conv_c(t_flags *meta, va_list *ap);
char				*wchar_to_wstr(int wchar);
void				conv_pourcent(t_flags *meta, va_list *ap);
void				conv_x(t_flags *meta, va_list *ap);
char				*fill_zero(int n);
void				conv_x(t_flags *meta, va_list *ap);
void				conv_o(t_flags *meta, va_list *ap);
void				conv_d(t_flags *meta, va_list *ap);
void				conv_u(t_flags *meta, va_list *ap);
char				*ft_itoa_u(uintmax_t n);
void				apply_mtag(char **str, int len);
void				apply_ztag(char **str);
void				conv_invalid(const char *format, t_flags *meta, int *i);
void				apply_ptag(char **str);
void				apply_sptag(char **str);
void				apply_prcs(char **nbr, int prcs);
void				apply_ctag(t_flags *meta, char **str);
void				conv_b(t_flags *meta, va_list *ap);
void				conv_n(t_flags *meta, va_list *ap);
void				color(const char *format, int *i);

#endif
