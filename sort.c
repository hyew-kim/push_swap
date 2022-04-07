#include "push_swap.h"

void	setSort(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	t_node	*node;

	a = stack->a;
	b = stack->b;
	arr = (int *)malloc(sizeof(int) * size(a));
	if (arr == NULL)
		return ;
	indexing(a, &arr);
	node = a->next;
	while (node)
	{
		node->content = *arr;
		node = node->next;
		arr++;
	}
	sort(stack);
	//print(stack);
	return ;
}
#include <stdio.h>
void	print(t_stack *stack)
{
	t_node *a = stack->a->next;
	t_node *b = stack->b->next;

	printf("A\n----\n");
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("B\n---\n");
	while (b)
	{
		printf("%d\n", b->content);
		b = b->next;
	}
}
void	indexing(t_node *head, int **arr)
{
	int		cnt;
	int		i;
	t_node	*node;
	t_node	*next_node;

	node = head->next;
	i = -1;
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
			if (node->content > next_node->content)
				++cnt;
			next_node = next_node->next;
		}
		(*arr)[++i] = cnt;
		node = node->next;
	}
}

void	sort(t_stack *stack)
{
	int	len;

	if (isSorted(stack->a))
		return ;
	len = size(stack->a);
	if (len <= 3)
		return (sortFewElements(stack, len));
	else if (len == 4)
		return (sortFour(stack, len));
	else if (len == 5)
		return (sortFive(stack, len));
	aToB(stack, len);
	bToA(stack, len);
}

int	isSorted(t_node *head)
{
	t_node	*node;

	node = head->next;
	while (node->next)
	{
		if (node->content >= node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int		getChunk(int len)
{
	if (len <= 100)
		return (15);
	else if (len <= 500)
		return (30);
	else if (len <= 1000)
		return (45);
	else if (len <= 2000)
		return (65);
	else
		return (150);
}

void	aToB(t_stack *stack, int len)
{
	int		num;
	int		chunk;
	t_node	*a;

	num = 0;
	chunk = getChunk(len);
	a = stack->a;
	while (!empty(a))
	{
		if (a->next->content <= num)
		{
			pb(stack);
			num++;
		}
		else if (a->next->content <= num + chunk)
		{
			pb(stack);
			rb(stack);
			num++;
		}
		else
			ra(stack);
	}
	return ;
}

void	bToA(t_stack *stack, int len)
{
	t_node	*b;
	int		maxIdx;

	b = stack->b;
	print(stack);
	while (!empty(b))
	{
		maxIdx = getIndexOfMax(b);
		if (maxIdx < len / 2)
		{
			while (b->next->content != maxIdx)
				rb(stack);
		}
		else
		{
			while (b->next->content != maxIdx)
				rrb(stack);
		}
		pa(stack);	
	}
	return ;
}