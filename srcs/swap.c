/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:04:25 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/12 12:54:02 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *stack)
{
	int	nb_tmp;
	int	index_tmp;
	if (!stack || !stack->next)
		return ;
	nb_tmp = stack->nbr;
	index_tmp = stack->index;
	stack->nbr = stack->next->nbr;
	stack->index = stack->next->index;
	stack->next->nbr = nb_tmp;
	stack->next->index = index_tmp;
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
