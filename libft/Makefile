# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:26:46 by asenat            #+#    #+#              #
#    Updated: 2016/11/24 09:58:04 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAG = -Wall -Wextra -Werror
RM = rm -Rf
SRC = ft_atoi.c ft_itoa.c ft_memmove.c ft_putstr.c \
	  ft_strdel.c ft_strlen.c ft_strnew.c ft_tolower.c \
	  ft_bzero.c ft_memalloc.c ft_memset.c ft_putstr_fd.c \
	  ft_strdup.c ft_strmap.c ft_strnstr.c ft_toupper.c \
	  ft_isalnum.c ft_memccpy.c ft_putchar.c ft_strcat.c \
	  ft_strequ.c ft_strmapi.c ft_strrchr.c ft_isalpha.c \
	  ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_striter.c \
	  ft_strncat.c ft_strsplit.c ft_isascii.c ft_memcmp.c \
	  ft_putendl.c ft_strclr.c ft_striteri.c ft_strncmp.c \
	  ft_strstr.c ft_isdigit.c ft_memcpy.c ft_putendl_fd.c \
	  ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strsub.c \
	  ft_isprint.c ft_memdel.c ft_putnbr.c ft_strcpy.c \
	  ft_strlcat.c ft_strnequ.c ft_strtrim.c ft_putnbr_fd.c \
	  ft_lstadd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstiter.c ft_lstmap.c ft_isspace.c ft_isblank.c \
	  ft_islower.c ft_isupper.c ft_strrev.c ft_pow.c ft_lstrev.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
