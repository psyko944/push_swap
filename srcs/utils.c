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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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
