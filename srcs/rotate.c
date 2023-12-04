/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:06:13 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:06:15 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = tmp;
	last->next->next = NULL;
}

void	ra(t_list **stack_a, char flag)
{
	rotate(stack_a);
	if (!flag)
		ft_putstr("ra\n");
}

void	rb(t_list **stack_b, char flag)
{
	rotate(stack_b);
	if (!flag)
		ft_putstr("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b, char flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!flag)
		ft_putstr("rr\n");
}
