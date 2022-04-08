/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:07:30 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:07:31 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	if (empty(stack->a))
		return ;
	node = stack->a->next;
	while (node && node->next)
	{
		tmp = node->content;
		node->content = node->next->content;
		node->next->content = tmp;
		node = node->next;
	}
	ft_putendl_fd("ra", 1);
	return ;
}

void	rb(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	if (empty(stack->b))
		return ;
	node = stack->b->next;
	while (node && node->next)
	{
		tmp = node->content;
		node->content = node->next->content;
		node->next->content = tmp;
		node = node->next;
	}
	ft_putendl_fd("rb", 1);
	return ;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	return ;
}
