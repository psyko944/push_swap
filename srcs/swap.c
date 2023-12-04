/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:06:22 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:06:24 by mekherbo         ###   ########.fr       */
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

void	sa(t_list *stack_a, char flag)
{
	swap(stack_a);
	if (!flag)
		ft_putstr("sa\n");
}

void	sb(t_list *stack_b, char flag)
{
	swap(stack_b);
	if (!flag)
		ft_putstr("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b, char flag)
{
	swap(stack_a);
	swap(stack_b);
	if (!flag)
		ft_putstr("ss\n");
}
