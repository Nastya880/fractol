# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:30:22 by tandroma          #+#    #+#              #
#    Updated: 2022/01/27 14:11:38 by tandroma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
LIBFT		= libft
LIBFT_LIB	= libft.a
MINI_LIB_X	= minilibx_mms_20200219
MINI_LIB_X_LIB	= libmlx.dylib

INCS		= includes/fractol.h includes/key_macos.h
SRCS		= create_fractols.c create_window.c ft_atoi_double.c hook.c main.c print.c set_color.c set_type.c
OBJS		= $(SRCS:.c=.o)

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		make -C $(MINI_LIB_X)
		mv $(LIBFT)/$(LIBFT_LIB) .
		mv $(MINI_LIB_X)/$(MINI_LIB_X_LIB) .
		$(CC) $(CFLAGS) -c $(SRCS) -I $(INCS)
		$(CC) $(CFLAGS) -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

clean:
		make -C $(LIBFT) clean
		make -C $(MINI_LIB_X)
		$(RM) $(OBJS) $(LIBFT_LIB) $(MINI_LIB_X_LIB)

fclean: clean
		make -C $(LIBFT) fclean
		make -C $(MINI_LIB_X) clean
		$(RM) $(NAME)

re : fclean all



