#include "push_swap.h"
/*List의 정보는 head에 담겨있다 !*/
/*head 값 안 담음, tail은 null*/
/*head 유효성 검사 안함*/
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

void	pushFront(t_node *head, int content)
{
	t_node	*new;
	t_node	*head_next;

	new = createNode(content);
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

void	pushBack(t_node *head, int content)
{
	t_node	*new;
	t_node	*last_node;

	new = createNode(content);
	if (new == NULL)
		return ;
	last_node = back(head);
	last_node->next = new;
	new->prev = last_node;
	return ;
}

void	popFront(t_node *head)
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

void	popBack(t_node *head)
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

int	findValue(t_node *head, int value)
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
	/*head and tail 제외*/
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