/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:04:04 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/08 20:04:06 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;

	stack.a = create_node(0);
	stack.b = create_node(0);
	if (stack.a == NULL || stack.b == NULL)
		print_error(&stack);
	check_input(argc, argv, &stack);
	set_sort(&stack);
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}

void	check_input(int argc, char *argv[], t_stack *stack)
{
	int		i;
	int		j;
	char	**arr;

	if (argc < 2)
		print_error(stack);
	i = 0;
	arr = NULL;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ') == -1)
			check_arr(argv[i], stack);
		else
		{
			arr = ft_split(argv[i], ' ');
			j = -1;
			while (arr[++j])
				check_arr(arr[j], stack);
		}
	}
	return ;
}

static long long	ft_atol(const char *str)
{
	int			neg;
	long long	num;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (neg < 0 && neg * num > 0)
		return (0);
	else if (neg > 0 && neg * num < 0)
		return (-1);
	return (neg * num);
}

void	check_arr(char *arr, t_stack *stack)
{
	int			i;
	long long	num;

	i = 0;
	while (++i < (int)ft_strlen(arr))
	{
		if (i != 0 && !ft_isdigit(arr[i]))
			print_error(stack);
	}
	num = ft_atol(arr);
	if (!ft_isdigit(arr[0]))
		i--;
	if (num > INT32_MAX || num < INT32_MIN)
		print_error(stack);
	set_stack(stack, num);
}

void	set_stack(t_stack *stack, int num)
{
	if (find_value(stack->a, num))
		print_error(stack);
	push_back(stack->a, num);
	return ;
}
