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
	return(aToB(stack, len));
}

void	aToB(t_stack *stack, int len)
{
	int	i;
	int	pivot;
	int	cntOfRa;
	int	cntOfPb;
	
	ft_putnbr_fd(len, 1);
	ft_putchar_fd('\n', 1);
	if (len == 1)
		return ;
	pivot = (getValueOfMin(stack->a) + getValueOfMax(stack->a)) / 2;
	initializeThree(&cntOfRa, &cntOfPb, &i);
	while (++i <= len)
	{
		if (stack->a->next->content > pivot)
		{
			ra(stack);
			cntOfRa++;
		}
		else
		{
			pb(stack);
			cntOfPb++;
		}
	}
	i = -1;
	while (++i < cntOfRa)
		rra(stack);
	printf("ra: %d pb: %d\n", cntOfRa, cntOfPb);
	aToB(stack, cntOfRa);
	bToA(stack, cntOfPb);
}

void	bToA(t_stack *stack, int len)
{
	int		pivot;
	int		cntOfRb;
	int		cntOfPa;
	int		i;
//3 4 0 2 1
	printf("B len: %d\n", len);
	if (len == 1)
	{
		pa(stack);
		return ;
	}
	i = -1;
	pivot = (getValueOfMin(stack->b) + getValueOfMax(stack->b)) / 2;
	initializeTwo(&cntOfRb, &cntOfPa);	
	while (++i < len)
	{
		printf("pivot: %d\n", pivot);
		if (stack->b->next->content > pivot)
		{
			pa(stack);
			cntOfPa++;
		}
		else
		{
			rb(stack);
			cntOfRb++;
		}
	}
	i = -1;
	while (++i < cntOfRb)
		rrb(stack);
	aToB(stack, cntOfPa);
	bToA(stack, len - cntOfPa);
	return ;
}