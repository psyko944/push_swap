/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:04:28 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:04:38 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cost(t_list *stack_a, t_list *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		stack_b->cost_b = stack_b->pos;
		if (stack_b->pos > size_b / 2)
			stack_b->cost_b = (size_b - stack_b->pos) * -1;
		stack_b->cost_a = stack_b->target_pos;
		printf("%d\n", stack_b->cost_a);
		if (stack_b->target_pos > size_a /2)
			stack_b->cost_a = (size_a - stack_b->target_pos) * - 1;
		stack_b = stack_b->next;
	}
}

void	select_move(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int min_cost;
	int	min_cost_a;
	int	min_cost_b;
	
	tmp = *stack_b;
	min_cost = INT_MAX;
	printf("==APU==\n\n\n\n");
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < min_cost)
		{
			min_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			min_cost_a = tmp->cost_a;
			min_cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, min_cost_a, min_cost_b);
}
