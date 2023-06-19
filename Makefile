# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 13:38:34 by tbolzan-          #+#    #+#              #
#    Updated: 2023/06/06 18:16:45 by tbolzan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = pipex

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

RM = rm -f

AR = ar -rsc

SRC = pipex.c pipex_main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@mv ./libft/$(LIBFT) .
	cc -Wall -Wextra -Werror $(OBJ) $(CFLAGS) -L. $(LIBFT) -o $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONE: all clean fclan re