#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/15 14:55:31 by yli               #+#    #+#              #
#    Updated: 2017/06/15 20:16:24 by yli              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler
CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./src/libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = filler.c \
	get_info.c \
	shift_piece.c \
	print_coor.c \
	loop_pieces.c \
	heat_map.c

OBJECTS = $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c -I . -I $(LIBFT_DIR) -o $@ $<

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

force:
	true

clean:
	/bin/rm -f $(OBJECTS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	cd $(LIBFT_DIR) && make fclean
	cd ../
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
