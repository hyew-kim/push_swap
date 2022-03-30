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
	int			i;
	int			j;
	int			zero;
	long long	num;
	int			flag;

	if (argc < 2)
		printError();
	i = 0;
	flag = 0;
	while (++i < argc)
	{
		j = -1;
		while (++j < ft_strlen(argv[i]))
		{
			if (j != 0 && !ft_isdigit(argv[i][j]))
				printError();
			if (flag == 0 && argv[i][j] == '0')
				zero++;
			else
				flag = 1;
		}
		num = ft_atoi(argv[i]);
		if (argv[i][0] != '0' && num == 0)
			printError();
		//ft_putnbr_fd(num, 1);
		if (!ft_isdigit(argv[i][0]))
			j--;
		//printf("\nj: %d, zero: %d\n", j, zero);
		if (j - zero > 10 || num > INT32_MAX || num < INT32_MIN)
			printError();
	}
	return ;
}

void	printError(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}