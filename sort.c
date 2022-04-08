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

	if (isSorted(stack->a, 0))
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

int	isPossiblePb(t_node *head, int pivot)
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

int	checkEndA(t_stack *stack, int len)
{
	if (len == 1 || isSorted(stack->a, 0))
		return (1);
	if (len == 2)
	{
		sortFewElements(stack, len);
		return (1);
	}
	return (0);
}

void	aToB(t_stack *stack, int len)
{
	int	i;
	int	pivot;
	int	cntOfRa;
	int	cntOfPb;
	
	//ft_putnbr_fd(len, 1);
	//ft_putchar_fd('\n', 1);
	if (checkEndA(stack, len))
		return ;
	pivot = getPivot(stack->a, len);
	initializeThree(&cntOfRa, &cntOfPb, &i);
	while (++i <= len && isPossiblePb(stack->a, pivot))
	{
		//ft_putnbr_fd(pivot, 1);
		//ft_putendl_fd(" a pivot", 1);
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
	//ft_putnbr_fd(cntOfPb, 1);
	//ft_putendl_fd(" pb value\n", 1);
	aToB(stack, len - cntOfPb);
	bToA(stack, cntOfPb);
}
int		checkEnd(t_stack *stack, int len)
{
	if (len == 1)
	{
		pa(stack);
		return (1);
	}	
	if (isSorted(stack->b, 1))
	{
		while (len-- > 0) 
			pa(stack);
		return (1);
	}
	return (0);
}

int	isPossiblePa(t_node *head, int pivot)
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
void	bToA(t_stack *stack, int len)
{
	int		pivot;
	int		cntOfRb;
	int		cntOfPa;
	int		i;
//3 4 0 2 1
	//printf("B len: %d\n", len);
	if (checkEnd(stack, len))
		return ;
	i = -1;
	pivot = getPivot(stack->b, len);
	initializeTwo(&cntOfRb, &cntOfPa);	
	while (++i < len && isPossiblePa(stack->b, pivot))
	{
		//printf("pivot: %d\n", pivot);
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