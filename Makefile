# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <asenat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 08:36:33 by asenat            #+#    #+#              #
#    Updated: 2016/11/24 11:40:02 by nbouchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		= gcc
FLAGS	= -Wall -Wextra -Werror
LIB		= libft/libft.a
LIBSRC	= libft/
NAME	= fillit
SRCDIR	= src/
OBJDIR	= ./
SRC		= reader.c 			\
		  tetros.c 			\
		  valid_tet.c		\
		  map.c				\
		  solving_file.c	\
		  main.c
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(SRC:.c=.o))
HEADER	= includes/

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) -L./$(LIBSRC) -lft -o $(NAME) $(OBJS)

objdir:
	@mkdir -p obj

$(LIB):
	make -C $(LIBSRC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)$(NAME).h
	$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER)

clean:
	rm -rf $(OBJS)
	make -C $(LIBSRC) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBSRC) fclean

re: fclean all

.PHONY: all clean fclean re
