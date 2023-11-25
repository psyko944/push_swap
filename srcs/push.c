/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:05:55 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:05:57 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **stack, t_list **push)
{
	t_list *new;
	if (!*push)
		return ;
	if (!*stack)
	{
		new = (*push)->next;
		*stack = *push;
		(*stack)->next = NULL;
		*push = new;
		return ;
	}
	new = (*push)->next;
	(*push)->next = *stack;
	*stack = *push;
	*push = new;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pb\n");
}
