/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkherbou <mkherbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:29:44 by mkherbou          #+#    #+#             */
/*   Updated: 2022/10/12 16:21:18 by mkherbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	resultat;

	i = 0;
	resultat = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 - 48 + str[i];
		i++;
	}
	if ((resultat * sign) < INT_MIN ||  (resultat * sign) > INT_MAX)
	{
		printf("nb invalide");
		exit(1);
	}
	return (int)(resultat * sign);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return NULL;
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return;
	}
	new->next = *lst;
	*lst = new;
}
