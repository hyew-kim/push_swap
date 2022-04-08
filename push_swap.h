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

typedef	struct		s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stack;

/*prototype*/
void				checkInput(int argc, char *argv[], t_stack *stack);
void				checkArr(char *arr, t_stack *stack);
void				printError(t_stack *stack);
t_node				*createNode(int content);
int					empty(t_node *head);
t_node				*back(t_node *head);
void				pushFront(t_node *head, int content);
void				pushBack(t_node *head, int content);
void				popFront(t_node *head);
void				popBack(t_node *head);
int					findValue(t_node *head, int value);
int					size(t_node *head);
void				setStack(t_stack *stack, int num);
void				freeStack(t_stack *stack);
void				setSort(t_stack *stack);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);
void				indexing(t_node *head, int **arr);
void				sort(t_stack *stack);
void	print(t_stack *stack);
int					isSorted(t_node *head, int flag);
void				sortFewElements(t_stack *stack, int len);
void				sortFour(t_stack *stack, int len);
void				sortFive(t_stack *stack, int len);
void				aToB(t_stack *stack, int len);
void				bToA(t_stack *stack, int len);
int					getChunk(int len);
int					getValueOfMin(t_node *head);
int					getValueOfMax(t_node *head);
int					getIndexOfMin(t_node *head);
int					getIndexOfMax(t_node *head);
int					checkCase(t_node *head);
#endif