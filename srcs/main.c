/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:24:46 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/25 00:29:51 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_list *stack)
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

static void	selection_sort(t_list **stack_a, t_list **stack_b, int stacklen)
{
	printf("valeur de stacklen : %d\n", stacklen);
	if (stacklen == 2)
		sa(*stack_a);
	else if (stacklen == 3)
		sort_for_three(stack_a);
	else
		sort(stack_a, stack_b, stacklen);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int stacklen;
	
	if (ac < 2)
	{
		printf("Error\n wrong number of arguments\n");
		return (0);
	}
	if (!check_arg(av))
	{
		printf("Error\n incorrect format\n");
		return (0);
	}
	stack_a = fill_stack(av);
	stack_b = NULL;
	stacklen = ft_lstsize(stack_a);
	if (!is_sorted(stack_a))
		selection_sort(&stack_a, &stack_b, stacklen);
	printf("==restack_b==\n");
	print_list(stack_b);
	printf("==dernier print==\n");
	print_list(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
