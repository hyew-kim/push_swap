/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:01:53 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:01:59 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_node *head, int flag)
{
	t_node	*node;

	node = head->next;
	while (node->next)
	{
		if (!flag && node->content >= node->next->content)
			return (0);
		if (flag && node->content < node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_value_min(t_node *head)
{
	t_node	*node;
	int		min;

	node = head->next;
	min = INT32_MAX;
	while (node)
	{
		if (min > node->content)
			min = node->content;
		node = node->next;
	}
	return (min);
}

int	get_index_min(t_node *head)
{
	t_node	*node;
	int		min;
	int		idx;

	node = head->next;
	min = get_value_min(head);
	idx = 0;
	while (node)
	{
		if (min == node->content)
			break ;
		node = node->next;
		idx++;
	}
	return (idx);
}

int	get_value_max(t_node *head)
{
	t_node	*node;
	int		max;

	node = head->next;
	max = -1;
	while (node)
	{
		if (max < node->content)
			max = node->content;
		node = node->next;
	}
	return (max);
}

int	get_index_max(t_node *head)
{
	t_node	*node;
	int		max;
	int		idx;

	node = head->next;
	max = get_value_max(head);
	idx = 0;
	while (node)
	{
		if (max == node->content)
			break ;
		node = node->next;
		idx++;
	}
	return (idx);
}
