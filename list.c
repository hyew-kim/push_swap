#include "push_swap.h"
/*List의 정보는 head에 담겨있다 !*/
t_node	*createNode(int content)
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

void	pushFront(t_node *head, int content)
{
	t_node	*new;
	t_node	*head_next;

	new = createNode(content);
	if (!new)
		return ;
	head_next = head->next;
	new->next = head->next;
	new->prev = head;
	head->next = new;
	if (head_next != NULL)
		head_next->prev = new;
	return ;
}

void	pushBack(t_node *head, int content)
{
	t_node	*new;
	t_node	*last_node;

	new = createNode(content);
	if (!new)
		return ;
	last_node = head;
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	last_node->next = new;
	new->prev = last_node;
	return ;
}

void	remove(t_node *head, int content)
{
	t_node	*find;

	find = head;
	while (find->content != content)
	{
		find = find->next;
	}
}