# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehakcan <mehakcan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:53:41 by mehakcan          #+#    #+#              #
#    Updated: 2024/03/14 12:58:16 by mehakcan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_UTILS = minitalk_utils.c

CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_UTILS) $(SRC_SERVER) -o $(SERVER)

$(CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_UTILS) $(SRC_CLIENT) -o $(CLIENT)

clean:
	$(RM) $(CLIENT) $(SERVER)
fclean:
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re