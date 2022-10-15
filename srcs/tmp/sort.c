/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:39:36 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/15 13:34:13 by sniperking       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_high_index(t_list *stack)
{
	if (!stack)
		return (0);
	int	i;

	i = 0;
	while (stack)
	{
		if (i < stack->index)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	sort_for_three(t_list *stack)
{
	if (!stack && !stack->next)
		return ;
	if (stack->index > stack->next->index)
		ra(&stack);
	else
		rra(&stack);
	if (stack->index > stack->next->index)
		sa(stack);
	printf("before sort\n");
	print_list(stack);
}

void sort(t_list **stack_a, t_list **stack_b, int stacklen)
{
	fill_stack_b(stack_b, stack_a, stacklen);
	//sort_for_three(stack_a);

}

void fill_stack_b(t_list **stack_b, t_list **stack_a, int stacklen)
{
	if (!*stack_a)
		return ;
	int	lentmp;
	
	lentmp = stacklen;
	while (*stack_a && stacklen > 3)
	{
		if ((*stack_a)->index < lentmp / 2)
			pb;
		else
			ra;
		stacklen--;
	}
}
