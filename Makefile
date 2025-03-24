CC = cc
CFLAGS = -Wall -Wextra -Werror
UTILS_SRC = ./ultims/ft_printf.c ./ultims/ft_putchar.c ./ultims/ft_putnbr.c ./ultims/ft_putnbr_u.c ./ultims/ft_putstr.c \
			./ultims/ft_putadd.c ./ultims/ft_puthexa.c ./ultims/ft_calloc.c ./ultims/ft_free.c ./ultims/ft_len.c ./ultims/ft_atoi.c
RM = rm -rf

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV = ./mandatory/server.c
SV_OBJ = $(SV:.c=.o)

CL = ./mandatory/client.c
CL_OBJ = $(CL:.c=.o)

SV_BONUS = ./bonus/server_bonus.c
SV_BONUS_OBJ = $(SV_BONUS:.c=.o)

CL_BONUS = ./bonus/client_bonus.c
CL_BONUS_OBJ = $(CL_BONUS:.c=.o)

UTILS_OBJ = $(UTILS_SRC:%.c=%.o)

all: $(UTILS_OBJ) $(SERVER) $(CLIENT)

bonus : $(UTILS_OBJ) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SV_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(SV_OBJ) $(UTILS_OBJ) -o server

$(CLIENT): $(CL_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(CL_OBJ) $(UTILS_OBJ) -o client


$(SERVER_BONUS): $(SV_BONUS_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(SV_BONUS_OBJ) $(UTILS_OBJ) -o server_bonus

$(CLIENT_BONUS): $(CL_BONUS_OBJ) $(UTILS_OBJ)
		$(CC) $(CFLAGS) $(CL_BONUS_OBJ) $(UTILS_OBJ) -o client_bonus

mandatory/%.o: mandatory/%.c mandatory/minitalk.h ./ultims/ultims.h
		$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/minitalk_bonus.h ./ultims/ultims.h
		$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_OBJ): ultims/%.o: ultims/%.c ultims/ultims.h
		$(MAKE) -C ./ultims

clean:
		$(RM) $(SV_OBJ) $(CL_OBJ)
		$(RM) $(SV_BONUS_OBJ) $(CL_BONUS_OBJ)
		$(MAKE) -C ./ultims clean

fclean: clean
		$(RM) $(SERVER) $(CLIENT)
		$(RM) $(CLIENT_BONUS) $(SERVER_BONUS)
		$(MAKE) -C ./ultims fclean

re: fclean all

