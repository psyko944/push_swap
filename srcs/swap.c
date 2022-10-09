/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:04:25 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/08 02:27:04 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *stack)
{
	int	tmp;
	if (!stack || !stack->next)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
}

void	sa(t_list *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
