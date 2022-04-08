#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	int	lenA;
	int	lenB;

	if (stack->a == NULL || stack->b == NULL)
		return ;
	lenA = size(stack->a);
	lenB = size(stack->b);
	while (lenA-- > 0)
		pop_back(stack->a);
	while (lenB-- > 0)
		pop_back(stack->b);
	free(stack->a);
	free(stack->b);
	return ;
}

void	print_error(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	exit(EXIT_FAILURE);
}