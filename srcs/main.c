#include "../push_swap.h"

int main(int ac, char **av)
{

	t_list	*stack_a;
	t_list	*stack_b;
	int stacklen;

	if (ac < 2)
	{
		ft_printf("Error\n wrong number of arguments\n");
		return (0);
	}
	while (*av)
		ft_printf("%s\n",*av++);
	if (!check_arg(av))
	{
		ft_printf("Error\n incorrect format\n");
		return (0);
	}
	stack_a = fill_stack(av);
	stack_b = NULL;
	stacklen = ft_lstsize(stack_a);
	print_list(stack_a);
	sa(stack_a);
	print_list(stack_a);
	(void)stack_b;
	(void)stacklen;
}
