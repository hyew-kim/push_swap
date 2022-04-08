#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_node	*head_a;
	t_node	*head_b;
	int		top;

	head_a = stack->a;
	head_b = stack->b;
	if (empty(head_b))
		return ;
	top = stack->b->next->content;
	push_front(head_a, top);
	pop_front(head_b);
	ft_putendl_fd("pa", 1);
	return ;
}

void	pb(t_stack *stack)
{
	t_node	*head_a;
	t_node	*head_b;
	int		top;

	head_a = stack->a;
	head_b = stack->b;
	if (empty(head_a))
		return ;
	top = stack->a->next->content;
	push_front(head_b, top);
	pop_front(head_a);
	ft_putendl_fd("pb", 1);
	return ;
}