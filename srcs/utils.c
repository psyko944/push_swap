/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:06:30 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:06:32 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/*void	print_list(t_list *stack)
{
	if (!stack)
		return ;
	printf("pile : \n");
	while (stack != NULL)
	{
		ft_printf("nombre : %d index : %d pos : %d\ttarget_pos : %d\tcost_a : %d cost_b : %d\n", stack->nbr, stack->index, stack->pos, stack->target_pos, stack->cost_a, stack->cost_b);
		stack = stack->next;
	}
	ft_printf("fin de pile\n\n");
}*/

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}

int	get_min_index(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	get_min_index_pos(t_list *stack)
{
	int	min_index_pos;
	int	min_index;

	min_index = INT_MAX;
	min_index_pos = stack->pos;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_index_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (min_index_pos);
}
