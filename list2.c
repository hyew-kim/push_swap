/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:54:30 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:09:41 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty(t_node *head)
{
	if (head->next == NULL)
		return (1);
	else
		return (0);
}

t_node	*back(t_node *head)
{
	t_node	*last_node;

	last_node = head;
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

int	find_value(t_node *head, int value)
{
	t_node	*find;

	find = head->next;
	while (find)
	{
		if (find->content == value)
			return (1);
		find = find->next;
	}
	return (0);
}

int	size(t_node *head)
{
	t_node	*node;
	int		len;

	node = head->next;
	len = 0;
	while (node)
	{
		++len;
		node = node->next;
	}
	return (len);
}
