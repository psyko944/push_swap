/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:13:48 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/09 03:25:53 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* struct for linked list */
typedef struct s_list
{	
	int nbr;
	int index;
	struct s_list *next;
}	t_list;


/*    libft functions       */
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
t_list *ft_lstlast(t_list *lst);
void	ft_putstr(char *str);

/* push_swap functions */
t_list	*fill_stack(char **av);
t_list	*new_stack(int nb);
t_list	*get_stack_before_last(t_list *stack);
void	add_numbers(t_list **stack_a, t_list *new);
//void	free_stack(t_list **stack);
void	print_list(t_list *stack);
int		is_sorted(t_list *stack);

/* actions functions */
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);

#endif
