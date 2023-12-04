/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:32:05 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/04 20:32:24 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	select_actions(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(*stack_a, 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(*stack_b, 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(*stack_a, *stack_b, 1);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(stack_a, 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(stack_a, 1);
	else if (!ft_strncmp(str, "rra\n", 3))
		rra(stack_a, 1);
	else if (!ft_strncmp(str, "rrb\n", 3))
		rrb(stack_a, 1);
	else if (!ft_strncmp(str, "rrr\n", 3))
		rrr(stack_a, stack_b, 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(stack_a, stack_b, 1);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(stack_b, stack_a, 1);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(stack_a, stack_b, 1);
	else
		ft_error();
}

static void	ft_parse(t_list **stack_a)
{
	char	*str;
	t_list	*stack_b;

	stack_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		select_actions(stack_a, &stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac < 2)
	{
		ft_printf("Error\n wrong number of arguments\n");
		return (0);
	}
	if (len_tab(av) == 2)
		av = ft_split(av[1], ' ');
	else
		av += 1;
	if (!check_arg(av))
	{
		ft_printf("Error\n incorrect format\n");
		return (0);
	}
	stack_a = fill_stack(av);
	if (!is_sorted(stack_a))
		ft_parse(&stack_a);
	if (is_sorted(stack_a))
		ft_printf(GREEN"OK\n"RESET);
	else
		ft_printf(RED"KO\n"RESET);
	return (0);
}
