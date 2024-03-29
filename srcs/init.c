/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:04:45 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:04:48 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_stack_before_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_list	*new_stack(int nb)
{
	t_list	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->nbr = nb;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_list	*fill_stack(char **av)
{
	t_list	*stack_a;
	int		nb;
	int		i;
	int		stacklen;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (i == 0)
			stack_a = new_stack((int)nb);
		else
			add_numbers(&stack_a, new_stack((int)nb));
		i++;
	}
	stacklen = ft_lstsize(stack_a);
	add_index(stack_a, stacklen);
	return (stack_a);
}

void	add_numbers(t_list **stack_a, t_list *new)
{
	t_list	*last_nb;

	if (!new)
		return ;
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	last_nb = ft_lstlast(*stack_a);
	last_nb->next = new;
}

void	add_index(t_list *stack, int stacklen)
{
	t_list	*before;
	t_list	*max_node;
	int		max;

	while (--stacklen)
	{
		before = stack;
		max = INT_MIN;
		max_node = NULL;
		while (before)
		{
			if (before->nbr > max && before->index == 0)
			{
				max = before->nbr;
				max_node = before;
				before = stack;
			}
			else
				before = before->next;
		}
		if (max_node != NULL)
			max_node->index = stacklen;
	}
}
