#include "push_swap.h"

void	sort_few_elements(t_stack *stack, int len)
{
	if (len == 1 || issorted(stack->a, 0))
		return ;
	else if (len == 2)
		sa(stack);
	else if (len == 3)
		sort_three(stack);
}

void	sort_three(t_stack *stack)
{
	int flag;

	flag = check_case(stack->a);
	if (flag == 1)
		sa(stack);
	else if (flag == 2)
	{
		sa(stack);
		rra(stack);
	}
	else if (flag == 3)
		ra(stack);
	else if (flag == 4)
	{
		sa(stack);
		ra(stack);
	}
	else if (flag == 5)
		rra(stack);
	return ;
}

int	check_case(t_node *head)
{
	t_node	*node;
	int		min;
	int		max;

	node = head->next;
	min = get_value_min(head);
	max = get_value_max(head);
	if (node->content == min)
		return (4);
	else if (node->content == max)
	{
		if (node->next->content == min)
			return (3);
		return (2);
	}
	else
	{
		if (node->next->content == min)
			return (1);
		return (5);
	}
}

void	sort_four(t_stack *stack, int len)
{
	int		min;
	t_node	*a;

	a = stack->a;
	min = get_value_min(a);
	while (a->next->content != min)
	{
		if (get_index_min(a) < len / 2)
			ra(stack);
		else
			rra(stack);
	}
	if (issorted(a, 0))
		return ;
	pb(stack);
	sort_three(stack);
	pa(stack);
	return;
}

void sort_five(t_stack *stack, int len)
{
	t_node	*a;
	int		min;

	a = stack->a;
	min = get_value_min(a);
	while (a->next->content != min)
	{
		if (get_index_min(a) < len / 2)
			ra(stack);
		else
			rra(stack);
	}
	if (issorted(a, 0))
		return ;
	pb(stack);
	sort_four(stack, len - 1);
	pa(stack);
	return ;
}