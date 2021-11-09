# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 09:43:27 by jgagnon           #+#    #+#              #
#    Updated: 2021/11/07 17:02:12 by jgagnon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS_FILES = 	ft_print_adress.c\
				ft_print_char.c\
				ft_print_decimal.c\
				ft_print_hex.c\
				ft_print_hx.c\
				ft_print_integer.c\
				ft_print_percent.c\
				ft_print_str.c\
				ft_print_unsigned.c\
				ft_printf.c\

OBJS_FILES = $(SRCS_FILES:.c=.o)

NORM = norminette

RM = rm -f

all: $(NAME)

$(NAME) : 	$(OBJS_FILES)
		ar rcs $(NAME) $(OBJS_FILES)
		@echo "_____printf.a créé avec succès_____"
clean:
	rm -rf $(OBJS_FILES)
	@echo "_____Les objets des fonctions ont été détruites_____"

fclean: clean
	rm -f $(NAME)
	@echo "_____Les textes anciens ont été brûlés_____"

re: fclean all
