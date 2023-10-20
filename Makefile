# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 16:21:55 by knishiok          #+#    #+#              #
#    Updated: 2023/10/18 22:40:55 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB = libft/libft.a

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): srcs/server_bonus.o libft
	$(CC) $(CFLAGS) $(INC) -o $@ $< $(LIB)

$(CLIENT_BONUS): srcs/client_bonus.o libft
	$(CC) $(CFLAGS) $(INC) -o $@ $< $(LIB)

$(SERVER): srcs/server.o libft
	$(CC) $(CFLAGS) $(INC) -o $@ $< $(LIB)

$(CLIENT): srcs/client.o libft
	$(CC) $(CFLAGS) $(INC) -o $@ $< $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

libft:
	make -C libft

clean:
	make clean -C libft
	$(RM) srcs/server_bonus.o srcs/client_bonus.o srcs/server.o srcs/client.o

fclean:
	make fclean -C libft
	$(RM) srcs/server_bonus.o srcs/client_bonus.o srcs/server.o srcs/client.o $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)


re: fclean all

.PHONY: all libft clean fclean
