#include "push_swap.h"

void	sortFewElements(t_stack *stack, int len)
{
	int	flag;

	if (len == 1 || isSorted(stack->a, 0))
		return ;
	else if (len == 2)
		sa(stack);
	else if (len == 3)
	{
		flag = checkCase(stack->a);
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
	}
}

int	checkCase(t_node *head)
{
	t_node	*node;
	int		min;
	int		max;

	node = head->next;
	min = getValueOfMin(head);
	max = getValueOfMax(head);
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

void	sortFour(t_stack *stack, int len)
{
	int	min;
	t_node	*a;

	a = stack->a;
	min = getValueOfMin(a);
	while (a->next->content != min)
	{
		if (getIndexOfMin(a) < len / 2)
			ra(stack);
		else
			rra(stack);
	}
	if (isSorted(a, 0))
		return ;
	pb(stack);
	sortFewElements(stack, 3);
	pa(stack);
	return;
}

void sortFive(t_stack *stack, int len)
{
	t_node	*a;
	int		min;

	a = stack->a;
	min = getValueOfMin(a);
	while (a->next->content != min)
	{
		if (getIndexOfMin(a) < len / 2)
			ra(stack);
		else
			rra(stack);
	}
	if (isSorted(a, 0))
		return ;
	pb(stack);
	sortFour(stack, len - 1);
	pa(stack);
	return ;
}