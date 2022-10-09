/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:05:18 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/09 03:25:23 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	if(!*stack || !(*stack)->next)
		return ;
	t_list	*tmp;
	t_list	*last;
	int	nb;

	/*tmp = *stack;
	last = ft_lstlast(stack);
	nb = last->nb;
	*stack = tmp;*/

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
