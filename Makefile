# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 17:04:02 by lasalced          #+#    #+#              #
#    Updated: 2015/10/22 14:28:57 by lasalced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		main.c parse.c parse_next.c lnode.c dijkstra.c \
				ft_lnode_methode.c parse_link.c

OBJ		=		${SRC:.c=.o}

LIB		=		libft/libft.a

INC		=		libft/includes

NAME	= 		lem-in

RM		=		rm -f

FLAG	=		-Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ) -L. $(LIB)

%.o:		%.c
		gcc $(FLAG) -c $< -o $@ -I $(INC)

libft/libft.a:
		make -C libft/

re:		fclean $(NAME)

clean:
		@$(RM) $(OBJ)
		make -C libft/ clean

fclean: clean
		@$(RM) $(NAME)
		make -C libft/ fclean
		@$(RM) libft.h.gch

.PHONY: clean fclean re all
