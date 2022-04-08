CC = gcc
CFLAGS = -g
#-Wextra -Wall -Werror
# -L : 라이브러리 경로 지정
AR = ar rcs

NAME = push_swap
SRC = push_swap.c\
	list.c\
	sort.c\
	command_swap.c\
	command_push.c\
	command_rotate.c\
	command_rrotate.c\
	few_element_sort.c\
	sort_utill.c\
	
OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C libft/ bonus
	$(CC) $(CFLAGS) $^ -o $@ libft/libft.a

all: $(NAME)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft.a
	make fclean -C libft/

clean:
	rm -rf $(OBJS)
	make clean -C libft/

re: fclean all