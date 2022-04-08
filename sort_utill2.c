/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:01:29 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:01:45 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_done_b(t_stack *stack, int len)
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
				continue ;
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
