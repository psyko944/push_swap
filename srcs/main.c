/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:24:46 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/09 02:38:53 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int		size;
	
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
	print_list(stack_a);
	print_list(stack_b);
	ra(&stack_a);
	print_list(stack_a);
	return (0);
}
