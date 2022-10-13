/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:24:46 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/13 18:52:58 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while(stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int check_double(char **av)
{
	int i;
	int j;
	int a;
	int b;
	int	k;

	a = 0;
	b = 0;
	i = 1;
	while(av[i])
	{
		k = 0;
		while(av[i][k])
		{
			if (av[i][0] == '+' || av[i][0] == '-')
				k++;
			if (!ft_isdigit(av[i][k]))
				return (1);
			k++;
		}
		j = i + 1;
		a = ft_atoi(av[i]);
		while(av[j])
		{
			b = ft_atoi(av[j]);
			if (a == b)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
	if (check_double(av))
	{
		printf("Error\n incorrect format\n");
		return (0);
	}
	stack_a = fill_stack(av);
	stack_b = NULL;
	stacklen = ft_lstsize(stack_a);
	(void)stacklen;
	(void)stack_b;
	print_list(stack_a);
	/*if (stacklen == 3)
		sort_for_three(stack_a);
	else
		printf("il n'y pas 3 nombres");
	printf("\nsort\n");
	if (is_sorted(stack_a))
		print_list(stack_a);
	else
		printf("la liste n'as pas ete triee\n");*/
	get_pos(stack_a);
	print_list(stack_a);
	ft_lstadd_front(&stack_b, new_stack(58));
	ft_lstadd_front(&stack_b, new_stack(88));
	get_target_pos(stack_a, stack_b);
	return (0);
}
