#include "push_swap.h"
int	main(int argc, char *argv[])
{
	t_stack	stack;
	/*Head 뒤부터 유효한 값!*/
	stack.a = createNode(0);
	stack.b = createNode(0);
	if (stack.a == NULL || stack.b == NULL)
		printError();
	checkInput(argc, argv, &stack);
	sort(&stack);
	exit(EXIT_SUCCESS);
}

void	checkInput(int argc, char *argv[], t_stack *stack)
{
	int		i;
	int		j;
	char	**arr;

	if (argc < 2)
		printError();
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

void	checkArr(char *arr, t_stack *stack)
{
	int			i;
	int			zero;
	long long	num;
	int			flag;

	i = -1;
	flag = 0;
	while (++i < ft_strlen(arr))
	{
		if (i != 0 && !ft_isdigit(arr[i]))
			printError();
		if (flag == 0 && arr[i]== '0')
			zero++;
		else
			flag = 1;
	}
	num = ft_atoi(arr);
	if (arr[i] != '0' && num == 0)
		printError();
	if (!ft_isdigit(arr[0]))
		i--;
	if (i - zero > 10 || num > INT32_MAX || num < INT32_MIN)
		printError();
	init(stack, num);
}

void	init(t_stack *stack, int num)
{
	if (findValue(stack->a, num))
		printError();
	pushBack(stack->a, num);
	return ;
}

void	printError(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}