# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpailhe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 23:21:27 by vpailhe           #+#    #+#              #
#    Updated: 2015/02/19 04:45:03 by vpailhe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

SRC = hud.c\
	  main.c\
	  key.c\
	  ./fractals/julia.c\
	  ./fractals/mandelbrot.c\
	  ./fractals/third.c\
	  ./draw/draw.c\

OBJ = hud.o\
	  main.o\
	  key.o\
	  julia.o\
	  third.o\
	  mandelbrot.o\
	  draw.o\

#FLAG = -Wall -Wextra -Werror

LIB = /usr/X11/lib -lmlx -lXext -lX11 -lm

INC = -I /usr/X11/include/X11

FLAG = -Wall -Wextra -Werror

.PHONY : libft.a

all : libft.a $(NAME)

libft.a:
	@$(MAKE) -C ./libft

$(OBJ):
	gcc -c -Ofast $(SRC) $(FLAG) libft/libft.a -L $(LIB) -I ./libft/includes

$(NAME): $(OBJ)
	gcc $(OBJ) libft/libft.a -L $(LIB) -I ./libft/includes -o $(NAME)

%.o: %.c
	gcc -I ./libft/includes -I /usr/X11/include/X11  -c $@ $^ 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
