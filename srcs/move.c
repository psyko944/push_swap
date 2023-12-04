/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:05:23 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:05:29 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	double_rotate(t_list **stack_a, t_list **stack_b,
	int *cost, int *cost2)
{
	while (*cost > 0 && *cost2 > 0)
	{
		(*cost)--;
		(*cost2)--;
		rr(stack_a, stack_b, 0);
	}
}

static void	double_rev_rotate(t_list **stack_a, t_list **stack_b,
	int *cost, int *cost2)
{
	while (*cost < 0 && *cost2 < 0)
	{
		(*cost)++;
		(*cost2)++;
		rrr(stack_a, stack_b, 0);
	}
}

static void	move_stack_a(t_list **stack_a, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ra(stack_a, 0);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			rra(stack_a, 0);
		}
	}
}

static void	move_stack_b(t_list **stack_b, int *cost2)
{
	while (*cost2 != 0)
	{
		if (*cost2 > 0)
		{
			(*cost2)--;
			rb(stack_b, 0);
		}
		else if (*cost2 < 0)
		{
			(*cost2)++;
			rrb(stack_b, 0);
		}
	}
}

void	move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		double_rev_rotate(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		double_rotate(stack_a, stack_b, &cost_a, &cost_b);
	move_stack_a(stack_a, &cost_a);
	move_stack_b(stack_b, &cost_b);
	pa(stack_a, stack_b, 0);
}
