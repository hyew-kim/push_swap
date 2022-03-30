#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*library*/
# include "./libft/libft.h"

/*struct*/
typedef	struct		s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/*prototype*/
void				checkInput(int argc, char *argv[]);
void				printError(void);
#endif
