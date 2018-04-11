#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 19:49:20 by msymkany          #+#    #+#              #
#    Updated: 2018/02/14 19:50:17 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

GL = -lm -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes/

SRCS = fdf.c \
        read_map.c \
        ft_usage.c \
        mlx_functions.c \
        calculate_map.c \
        move_it.c \

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(GL) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft

%.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libft.a:
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR) 

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR) 

re:  all
	make re -C $(LIBFTDIR)

norm:
	norminette srcs/ includes/*.h
	make norm -C $(LIBFTDIR)

rmsh:
	find . -name ".DS*" -o -name "._.*" -o -name "#*" -o -name "*~" -o -name "*.out" > rmsh
	xargs rm < rmsh
	rm rmsh
