# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 15:09:28 by aidrissi          #+#    #+#              #
#    Updated: 2019/12/21 16:53:55 by aidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_adresse.c ft_convert_base.c ft_flags_calcul.c ft_printf.c \
		ft_unsint.c ft_car.c ft_entier.c ft_hexa.c ft_string.c util.c \
		ft_prcentage.c ft_uitoa.c libft_util.c libft_util1.c\
		libft_util2.c

OUTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OUTS) 
		    ar rcs $(NAME) $(OUTS)

%.o : %.c 
	gcc -Wall -Wextra -Werror -c $<

clean :
	    /bin/rm -rf $(OUTS)

fclean : clean
	    /bin/rm -rf $(NAME)

re : fclean all
