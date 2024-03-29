/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:05:41 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:05:46 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_min_index(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	get_pos(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

static int	find_target(t_list **stack_a, int index, int target_pos)
{
	t_list	*tmp;
	int		max;

	max = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < max)
		{
			max = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (max != INT_MAX)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == get_min_index(*stack_a))
			target_pos = tmp->pos;
		tmp = tmp->next;
	}
	return (target_pos);
}

void	get_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		target_pos;

	if (!*stack_a || !stack_b)
		return ;
	get_pos(*stack_a);
	get_pos(*stack_b);
	tmp_b = *stack_b;
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = find_target(stack_a, tmp_b->index, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
