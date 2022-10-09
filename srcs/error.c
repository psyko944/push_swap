/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:21:24 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/08 02:25:19 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*void	free_stack(t_list **stack)
{
	t_list *tmp;

	while(*stack && *stack->next)
	{
		tmp = *stack;
		free(*stack);
		stack = tmp->next;
	}
}*/

void	print_list(t_list *stack)
{
	if (!stack)
		return ;
	printf("pile : \n");
	while (stack != NULL)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
	printf("fin de pile\n\n");
}
