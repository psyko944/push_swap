/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:05:18 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/12 16:58:02 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	if(!*stack || !(*stack)->next)
		return ;
	t_list	*tmp;
	t_list	*last;
	//int	nb;

	tmp = *stack;
	last = ft_lstlast(*stack);
	ft_lstadd_front(stack, last);
	*stack = tmp;
	tmp = get_stack_before_last(*stack);
	tmp->next = NULL;
	//free(last);
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a,t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
