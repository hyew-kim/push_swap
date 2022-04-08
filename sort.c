#include "push_swap.h"

void	set_sort(t_stack *stack)
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
	return ;
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

	if (issorted(stack->a, 0))
		return ;
	len = size(stack->a);
	if (len <= 3)
		return (sort_few_elements(stack, len));
	else if (len == 4)
		return (sort_four(stack, len));
	else if (len == 5)
		return (sort_five(stack, len));
	return(a_to_b(stack, len));
}

int	get_pivot(t_node *head, int length)
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

void	a_to_b(t_stack *stack, int len)
{
	int	i;
	int	pivot;
	int	cnt_ra;
	int	cnt_pb;
	
	if (is_done_a(stack, len))
		return ;
	pivot = get_pivot(stack->a, len);
	initialize_three(&cnt_ra, &cnt_pb, &i);
	while (++i <= len && is_possible_pb(stack->a, pivot))
	{
		if (stack->a->next->content > pivot)
		{
			ra(stack);
			cnt_ra++;
		}
		else
		{
			pb(stack);
			cnt_pb++;
		}
	}
	i = -1;
	while (++i < cnt_ra)
		rra(stack);
	a_to_b(stack, len - cnt_pb);
	b_to_a(stack, cnt_pb);
}

void	b_to_a(t_stack *stack, int len)
{
	int		pivot;
	int		cnt_rb;
	int		cnt_pa;
	int		i;

	if (is_done_b(stack, len))
		return ;
	pivot = get_pivot(stack->b, len);
	initialize_three(&cnt_rb, &cnt_pa, &i);	
	while (++i <= len && is_possible_pa(stack->b, pivot))
	{
		if (stack->b->next->content > pivot)
		{
			pa(stack);
			cnt_pa++;
		}
		else
		{
			rb(stack);
			cnt_rb++;
		}
	}
	i = -1;
	while (++i < cnt_rb)
		rrb(stack);
	a_to_b(stack, cnt_pa);
	b_to_a(stack, len - cnt_pa);
	return ;
}