/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:06:57 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:06:58 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*head;
	t_node	*first;
	t_node	*second;
	int		tmp;

	head = stack->a;
	if (empty(head) || size(head) < 2)
		return ;
	first = head->next;
	second = head->next->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
	ft_putendl_fd("sa", 1);
	return ;
}

void	sb(t_stack *stack)
{
	t_node	*head;
	t_node	*first;
	t_node	*second;
	int		tmp;

	head = stack->b;
	if (empty(head) || size(head) < 2)
		return ;
	first = head->next;
	second = head->next->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
	ft_putendl_fd("sb", 1);
	return ;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	return ;
}
