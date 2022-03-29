CC = gcc
CFLAGS = -g
#-Wextra -Wall -Werror
# -L : 라이브러리 경로 지정
AR = ar rcs

NAME = push_swap
SRC = *.c
OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C libft/ bonus
	cp libft/libft.a ./
	$(CC) $(CFLAGS) $^ -o $@ 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft.a
	make fclean -C libft/

clean:
	rm -rf $(OBJS)
	make clean -C libft/

re: fclean all