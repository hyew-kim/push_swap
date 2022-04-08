#include "push_swap.h"

int	is_done_a(t_stack *stack, int len)
{
	if (len == 1 || issorted(stack->a, 0))
		return (1);
	if (len == 2)
	{
		sort_few_elements(stack, len);
		return (1);
	}
	return (0);
}

int		is_done_b(t_stack *stack, int len)
{
	if (len == 1)
	{
		pa(stack);
		return (1);
	}	
	if (issorted(stack->b, 1))
	{
		while (len-- > 0) 
			pa(stack);
		return (1);
	}
	return (0);
}

int	is_possible_pb(t_node *head, int pivot)
{
	t_node	*node;

	node = head->next;
	while (node)
	{
		if (node->content <= pivot)
			return (1);
		node = node->next;
	}
	return (0);
}

int	is_possible_pa(t_node *head, int pivot)
{
	t_node	*node;

	node = head->next;
	while (node)
	{
		if (node->content > pivot)
			return (1);
		node = node->next;
	}
	return (0);
}