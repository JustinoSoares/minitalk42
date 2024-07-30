# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 17:45:12 by jsoares           #+#    #+#              #
#    Updated: 2024/07/21 12:20:04 by jsoares          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_SERVER = server.c
DIR_CLIENT = client.c
OBJ_CLIENT = $(DIR_CLIENT: .c=.o)
OBJ_SERVER = $(DIR_SERVER: .c=.o)
OBJ_S = server.o 
OBJ_C = client.o 
CLIENT = client
SERVER = server
INCLUDE = -I./include

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_C) 
			$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_C)

$(SERVER):  $(OBJ_S)
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_S) 
clean:
			rm -f $(OBJ_C) $(OBJ_S)
fclean:
			rm -f $(OBJ_C) $(OBJ_S)
			rm -f $(CLIENT) $(SERVER)
re: fclean all

.PHONY: all clean fclean re
