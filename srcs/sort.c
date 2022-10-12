/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:39:36 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/12 11:23:44 by mkherbou         ###   ########.fr       */
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
		rra(&stack);
}

/*void sort(t_list **stack_a, t_list **stack_b)
{
	fill_stack_b(stack_b, stack_a);
	sort_for_three(stack_a);

}

void fill_stack_b(t_list **stack_b, t_list **stack_a, int stacklen)
{
	if (!*stack_a)
		return ;
	while (stack_a && stacklen > 3)
	{
		pb;
		stack = stack->next;
		stacklen--;
	}
}*/
