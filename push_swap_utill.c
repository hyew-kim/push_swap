/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:55:55 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 19:56:50 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	int	len_a;
	int	len_b;

	if (stack->a == NULL || stack->b == NULL)
		return ;
	len_a = size(stack->a);
	len_b = size(stack->b);
	while (len_a-- > 0)
		pop_back(stack->a);
	while (len_b-- > 0)
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
