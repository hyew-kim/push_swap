/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:51:58 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:09:32 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_front(t_node *head, int content)
{
	t_node	*new;
	t_node	*head_next;

	new = create_node(content);
	if (new == NULL)
		return ;
	head_next = head->next;
	new->next = head->next;
	new->prev = head;
	head->next = new;
	if (head_next != NULL)
		head_next->prev = new;
	return ;
}

void	push_back(t_node *head, int content)
{
	t_node	*new;
	t_node	*last_node;

	new = create_node(content);
	if (new == NULL)
		return ;
	last_node = back(head);
	last_node->next = new;
	new->prev = last_node;
	return ;
}

void	pop_front(t_node *head)
{
	t_node	*del;

	if (empty(head))
		return ;
	del = head->next;
	head->next = del->next;
	if (del->next)
		del->next->prev = head;
	free(del);
	return ;
}

void	pop_back(t_node *head)
{
	t_node	*del;

	if (empty(head))
		return ;
	del = head;
	while (del->next)
		del = del->next;
	del->prev->next = NULL;
	free(del);
}
