/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:04:16 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/25 23:04:22 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <ctype.h>

int	len_tab(char **av)
{
	int	i;

	i = 0;
	while (av[i++])
	{
		if (!ft_strlen(av[i]))
			return (i);
	}
	return (i);
}

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '+' || (av[0] == '-' && av[1] != '\0'))
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_double(char **av)
{
	int	i;
	int	j;
	int	k;
	int	a;

	i = 0;
	while (av[i])
	{
		a = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			k = ft_atoi(av[j]);
			if (a == k)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	if (!check_double(av))
	{
		puts("ya des doublons ma gueule\n");
		return (0);
	}
	return (1);
}
