#include "push_swap.h"

void	sortFewElements(t_stack *stack, int len)
{
	int	flag;

	if (len == 1 || isSorted(stack->a))
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
	return ;
}

int	checkCase(t_node *head)
{
	t_node	*node;

	node = head->next;
	if (node->content == 0)
		return (4);
	else if (node->content == 1)
	{
		if (node->next->content == 0)
			return (1);
		return (5);
	}
	else if (node->content == 2)
	{
		if (node->next->content == 1)
			return (2);
		return (3);
	}
}

void	sortFourAndFive(t_stack *stack, int len)
{
	return;
}