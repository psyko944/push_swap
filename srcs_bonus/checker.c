#include "../push_swap.h"
#include "get_next_line.h"

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}


void  ft_parse(t_list **stack_a, t_list **stack_b, int stacklen)
{
	char *str;

	str = get_next_line(0);
	while (str && ft_strlen(str) == 2)
	{

		get_next_line

	}
	if (sorted(stack_a))
		printf("OK\n");
	else 
		printf("KO\n");	
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stacklen;

	if (ac < 2)
	{
		ft_printf("Error\n wrong number of arguments\n");
		return (0);
	}
	if (len_tab(av) == 2)
		av = ft_split(av[1], ' ');
	else
		av += 1;
	if (!check_arg(av))
	{
		ft_printf("Error\n incorrect format\n");
		return (0);
	}
	stack_a = fill_stack(av);
	stack_b = NULL;
	stacklen = ft_lstsize(stack_a);
	if (!is_sorted(stack_a))
		ft_parse(&stack_a, &stack_b, stacklen);

	ft_printf("test\n");	
}


