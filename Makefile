# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 08:42:40 by czalewsk          #+#    #+#              #
#    Updated: 2017/09/19 09:25:07 by czalewsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./ft_ls
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
SRCS = ft_ls.c ls_display.c ls_display_col.c ls_display_error.c \
	   ls_display_ext.c ls_display_ext2.c ls_display_folders.c \
	   ls_format_ext_line.c ls_get_col.c ls_init_list.c ls_set_display.c \
	   ls_sort.c ls_wrapper.c main.c

INCLUDES = -I ./libft

DEP = Makefile ft_ls.h ./libft/libft.a

LIBNAME = -lft
LIBPATH = ./libft
LIB = -L $(LIBPATH)

all: mylibft $(NAME)

$(NAME): $(OBJS)
	gcc $(LIB) $(LIBNAME) $(FLAGS) $(OBJS) -o $(NAME)

mylibft:
	make -C $(LIBPATH)

%.o: %.c $(DEP)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBPATH) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.NOTPARELLEL: all clean fclean re
