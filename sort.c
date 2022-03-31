#include "push_swap.h"

/*command실행 및 스택 a 초기화 작업*/

void	init(t_stack *stack, char *argv[])
{
	int	i;
	int num;

	i = 1;
	ft_putendl_fd("\nAtoi: ", 1);
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		ft_putnbr_fd(num ,1);
		if (findValue(stack->a, num))
			printError();
		pushBack(stack->a, num);
		++i;
	}
}

void	sort(t_stack *stack)
{
	t_node* tmp = stack->a; 
	t_node* tmp2 = stack->b;
	//sa(stack);
	//pb(stack);
	//pb(stack);
	//pushBack(stack->b, 99);
	//rr(stack);
	rrr(stack);
	ft_putendl_fd("\nPrint: ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->content, 1);
		tmp= tmp->next;
	}
	ft_putchar_fd('\n', 1);
	while (tmp2)
	{
		ft_putnbr_fd(tmp2->content, 1);
		tmp2= tmp2->next;
	}
}