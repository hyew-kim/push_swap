#include "push_swap.h"
int	main(int argc, char *argv[])
{
	t_stack	stack;

	checkInput(argc, argv);
	ft_putstr_fd("Check OK\n",1);
	/*Head 뒤부터 유효한 값!*/
	stack.a = createNode(0);
	stack.b = createNode(0);
	if (stack.a == NULL || stack.b == NULL)
		printError();
	init(&stack, argv);
	sort(&stack);
	exit(EXIT_SUCCESS);
}


#include <stdio.h>
void	checkInput(int argc, char *argv[])
{
	int	i;
	char **arr;

	if (argc < 2)
		printError();
	i = 0;
	arr = NULL;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ') == -1)
			checkArr(argv[i]);
		else
		{
			arr = ft_split(argv[i], ' ');
			int j = -1;
			while (++j < ft_strlen(arr))
				checkArr(arr[j]);
		}
	}
	return ;
}

void	checkArr(char *arr)
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
	//ft_putnbr_fd(num, 1);
	if (!ft_isdigit(arr[0]))
		i--;
	//printf("\nj: %d, zero: %d\n", j, zero);
	if (i - zero > 10 || num > INT32_MAX || num < INT32_MIN)
		printError();
}

void	printError(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}