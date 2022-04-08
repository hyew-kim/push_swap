#include "push_swap.h"

int	isSorted(t_node *head, int flag)
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

int	getValueOfMin(t_node *head)
{
	t_node *node;
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

int	getIndexOfMin(t_node *head)
{
	t_node *node;
	int		min;
	int		idx;

	node = head->next;
	min = getValueOfMin(head);
	idx = 0;
	while (node)
	{
		if (min == node->content)
			break;
		node = node->next;
		idx++;
	}
	return (idx);
}

int	getValueOfMax(t_node *head)
{
	t_node *node;
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

int	getIndexOfMax(t_node *head)
{
	t_node *node;
	int		max;
	int		idx;

	node = head->next;
	max = getValueOfMax(head);
	idx = 0;
	while (node)
	{
		if (max == node->content)
			break;
		node = node->next;
		idx++;
	}
	return (idx);
}