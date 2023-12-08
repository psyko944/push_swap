/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:45:38 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/01 13:45:41 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

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

static void	selection_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		stacklen;

	stack_b = NULL;
	stacklen = ft_lstsize(*stack_a);
	if (stacklen == 2)
		sa(*stack_a, 0);
	else if (stacklen == 3)
		sort_for_three(stack_a);
	else
		sort(stack_a, &stack_b, stacklen);
}

static int	ft_parse(char **av, int *flag)
{
	if (!check_arg(av))
	{
		write(2, "Error\n", 6);
		if (*flag)
			free_tab(av);
		exit(1);
	}	
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		flag;

	flag = 0;
	if (ac < 2)
		return (0);
	if (len_tab(av) == 2)
	{
		av = ft_split(av[1], ' ');
		flag = 1;
	}
	else
		av += 1;
	if (!ft_parse(av, &flag))
		return (0);
	stack_a = fill_stack(av);
	if (!is_sorted(stack_a))
		selection_sort(&stack_a);
	free_stack(&stack_a);
	if (flag)
		free_tab(av);
	return (0);
}
