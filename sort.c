#include "push_swap.h"
#include <stdio.h>
void	sort(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	a = stack->a;
	b = stack->b;
	// getPivot 실행 전에 빈 스택인 경우 실행 안되게 하기
	pb(stack);
	printf("%d %d", getPivot(a, size(a)), getPivot(b, size(b)));
}

int	getPivot(t_node *head, int length)
{
	int		cnt;
	t_node	*node;
	t_node	*next_node;

	node = head->next;
	while (node)
	{
		next_node = head->next;
		cnt = 0;
		while (next_node)
		{
			if (next_node == node)
			{
				next_node = next_node->next;
				continue;
			}
			if (node->content < next_node->content)
				++cnt;
			next_node = next_node->next;
		}
		if (cnt == length / 2)
			return (node->content);
		node = node->next;
	}
	return (head->next->content);
}