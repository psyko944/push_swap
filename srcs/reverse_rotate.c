/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:06:04 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:06:05 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	before_last = get_stack_before_last(*stack);
	*stack = before_last;
	(*stack)->next = NULL;
	last->next = tmp;
	*stack = last;
}

void	rra(t_list **stack_a, char flag)
{
	reverse_rotate(stack_a);
	if (!flag)
		ft_putstr("rra\n");
}

void	rrb(t_list **stack_b, char flag)
{
	reverse_rotate(stack_b);
	if (!flag)
		ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b, char flag)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!flag)
		ft_putstr("rrr\n");
}
