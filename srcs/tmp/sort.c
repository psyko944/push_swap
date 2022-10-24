/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:39:36 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/25 01:30:02 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_high_index(t_list *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		if (i < stack->index)
			i = stack->index;
		
		stack = stack->next;
	}
	return (i);
}

void	sort_for_three(t_list **stack)
{
	int max_index;

	if (!*stack && !(*stack)->next || is_sorted(*stack))
		return ;
	max_index = get_high_index(*stack);
	if ((*stack)->index == max_index)
		ra(stack);
	else if ((*stack)->next->index == max_index)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(*stack);
}

static void	fill_stack_b(t_list **stack_b, t_list **stack_a, int stacklen)
{
	int	lentmp;
	int	number_b;

	number_b = 0;
	lentmp = stacklen;
	if (!*stack_a)
		return ;
	while (stacklen > 6 && number_b < lentmp / 2)
	{
		if ((*stack_a)->index < lentmp / 2)
		{
			pb(stack_b, stack_a);
			number_b++;
		}
		else
			ra(stack_a);
		stacklen--;
	}
	while(lentmp - number_b > 3)
	{
		pb(stack_b, stack_a);
		number_b++;
	}
	
}

static void	move_to_top(t_list **stack_a)
{
	int	min_index_pos;
	int	stacklen;

	stacklen = ft_lstsize(*stack_a);
	min_index_pos = get_min_index_pos(*stack_a);
	if (min_index_pos > stacklen / 2)
	{
		while (min_index_pos < stacklen)
		{
			rra(stack_a);
			min_index_pos++;
		}
	}
	else
	{
		while (min_index_pos > 0)
		{
			ra(stack_a);
			min_index_pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b, int stacklen)
{
	fill_stack_b(stack_b, stack_a, stacklen);
	sort_for_three(stack_a);
	get_target_pos(stack_a, stack_b);
	get_cost(*stack_a, *stack_b);
	select_move(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		move_to_top(stack_a);
	/*while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(*stack_a, *stack_b);
		select_move(stack_a, stack_b);
	}*/
	/*if (!is_sorted(*stack_a))
		move_to_top(stack_a);*/
}
