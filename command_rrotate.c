#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*head;
	t_node	*last_node;

	if (empty(stack->a))
		return ;
	head = stack->a;
	last_node = back(head);
	push_front(head, last_node->content);
	pop_back(head);
	ft_putendl_fd("rra", 1);
	return ;
}

void	rrb(t_stack *stack)
{
	t_node	*head;
	t_node	*last_node;

	if (empty(stack->b))
		return ;
	head = stack->b;
	last_node = back(head);
	push_front(head, last_node->content);
	pop_back(head);
	ft_putendl_fd("rrb", 1);
	return ;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	return ;
}