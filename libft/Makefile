# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 13:16:18 by czalewsk          #+#    #+#              #
#    Updated: 2017/05/05 16:18:22 by lduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
OBJ = ft_strlen.o			\
	  ft_strisnumber.o		\
	  ft_strdup.o			\
	  ft_strcpy.o			\
	  ft_strncpy.o			\
	  ft_strcat.o			\
	  ft_strncat.o			\
	  ft_strlcat.o			\
	  ft_strrchr.o			\
	  ft_strstr.o			\
	  ft_strcmp.o			\
	  ft_strncmp.o			\
	  ft_atoi.o				\
	  ft_isdigit.o			\
	  ft_isalnum.o			\
	  ft_isascii.o			\
	  ft_isprint.o			\
	  ft_toupper.o			\
	  ft_tolower.o			\
	  ft_strchr.o			\
	  ft_strnstr.o			\
	  ft_isalpha.o			\
	  ft_memset.o			\
	  ft_bzero.o			\
	  ft_memcpy.o			\
	  ft_memccpy.o			\
	  ft_memmove.o			\
	  ft_memchr.o			\
	  ft_memcmp.o			\
	  ft_memalloc.o 		\
	  ft_memdel.o			\
	  ft_strnew.o			\
	  ft_strdel.o			\
	  ft_strrstr.o          \
	  ft_strclr.o			\
	  ft_striter.o			\
	  ft_striteri.o			\
	  ft_strmap.o			\
	  ft_strmapi.o			\
	  ft_strequ.o			\
	  ft_strnequ.o			\
	  ft_strsub.o			\
	  ft_strjoin.o			\
	  ft_strtrim.o			\
	  ft_strsplit.o			\
	  ft_putstr.o			\
	  ft_putchar.o			\
	  ft_putnbr.o			\
	  ft_putchar_fd.o		\
	  ft_putendl.o			\
	  ft_putstr_fd.o		\
	  ft_putendl_fd.o		\
	  ft_putnbr_fd.o		\
	  ft_lstnew.o			\
	  ft_lstdelone.o		\
	  ft_lstdel.o			\
	  ft_lstadd.o			\
	  ft_itoa.o				\
	  ft_lstiter.o			\
	  ft_lst_pushend.o		\
	  ft_lstmap.o			\
	  ft_lstlen.o			\
	  ft_strsplit_lst.o		\
	  ft_lst_newstr.o		\
	  ft_memdup.o			\
	  ft_square.o			\
	  ft_lst_remove_if.o	\
	  ft_lst_remove.o		\
	  ft_strjoin_free.o		\
	  ft_memrealloc.o		\
	  ft_memjoin_free.o		\
	  ft_power.o			\
	  ft_atoi_base.o		\
	  ft_itoa_base.o		\
	  ft_printf.o			\
	  fill_buffer.o			\
	  is_option.o			\
	  parsing.o				\
	  conv_s.o				\
	  wstr_to_str.o			\
	  ft_wstrlen.o			\
	  ft_strlen_utf.o		\
	  conv_p.o				\
	  min_width.o			\
	  conv_c.o				\
	  conv_pourcent.o		\
	  conv_x.o				\
	  fill_zero.o			\
	  conv_o.o				\
	  conv_d.o				\
	  conv_u.o				\
	  ft_itoa_u.o			\
	  apply_mtag.o			\
	  apply_ztag.o			\
	  conv_invalid.o		\
	  apply_ptag.o			\
	  apply_sptag.o			\
	  apply_prcs.o			\
	  ft_count_digit.o		\
	  apply_ctag.o			\
	  conv_b.o				\
	  conv_n.o				\
	  get_next_line.o		\
	  ft_isint.o			\
	  color.o				\
	  ft_howmany.o			\
	  array.o				\
	  array1.o				\
	  ft_lst_remove_last.o	\
	  ft_lst_remove_index.o	\
	  ft_lst_cpy.o			\
	  ft_lstinsert_if_end.o	\
	  ft_error.o			\
	  ft_strcstr.o			\
	  ft_isdouble.o			\
	  ft_atol.o				\
	  ft_lst_return_index.o	\
	  ft_isprint_wsp.o		\
	  ft_atoi_bigendian.o	\
	  ft_intisbetween_inc.o \
	  ft_cfextension.o		\


all : $(NAME)

$(NAME) : $(OBJ) 
	ar rc $(NAME) $(OBJ) && ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
