#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;
	/*Head 뒤부터 유효한 값!*/
	stack.a = createNode(0);
	stack.b = createNode(0);
	if (stack.a == NULL || stack.b == NULL)
		printError(&stack);
	checkInput(argc, argv, &stack);
	setSort(&stack);
	freeStack(&stack);
	exit(EXIT_SUCCESS);
}

void	checkInput(int argc, char *argv[], t_stack *stack)
{
	int		i;
	int		j;
	char	**arr;

	if (argc < 2)
		printError(stack);
	i = 0;
	arr = NULL;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ') == -1)
			checkArr(argv[i], stack);
		else
		{
			arr = ft_split(argv[i], ' ');
			j = -1;
			while (arr[++j])
				checkArr(arr[j], stack);
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

void	checkArr(char *arr, t_stack *stack)
{
	int			i;
	long long	num;

	while (++i < ft_strlen(arr))
	{
		if (i != 0 && !ft_isdigit(arr[i])) // 부호체크
			printError(stack);
	}
	num = ft_atol(arr);
	if (!ft_isdigit(arr[0]))
		i--;
	if (num > INT32_MAX || num < INT32_MIN)
		printError(stack);
	setStack(stack, num);
}

void	setStack(t_stack *stack, int num)
{
	if (findValue(stack->a, num))
		printError(stack);
	pushBack(stack->a, num);
	return ;
}

void	freeStack(t_stack *stack)
{
	int	lenA;
	int	lenB;

	if (stack->a == NULL || stack->b == NULL)
		return ;
	lenA = size(stack->a);
	lenB = size(stack->b);
	while (lenA-- > 0)
		popBack(stack->a);
	while (lenB-- > 0)
		popBack(stack->b);
	free(stack->a);
	free(stack->b);
	return ;
}

void	printError(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	freeStack(stack);
	exit(EXIT_FAILURE);
}