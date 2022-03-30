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

typedef struct		s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stack;

/*prototype*/
void				checkInput(int argc, char *argv[]);
void				printError(void);
t_node				*createNode(int content);
int					empty(t_node *head);
void				pushFront(t_node *head, int content);
void				pushBack(t_node *head, int content);
void				popFront(t_node *head);
void				popBack(t_node *head);
int					findValue(t_node *head, int value);
int					size(t_node *head);
void				init(t_stack *stack, char *argv[]);
void				sort(t_stack *stack);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
#endif