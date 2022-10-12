/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:19:22 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/12 10:07:16 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	int tmp;
	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->nbr;
	*stack = (*stack)->next;
	add_numbers(stack, new_stack(tmp));
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
