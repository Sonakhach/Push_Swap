/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:05:36 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/19 17:58:32 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char	*str)
{
	int		i;
	int		j;
	long	res;

	i = 0;
	res = 0;
	j = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * j);
}

void	ra(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	first = s->a;
	second = s->a->next;
	while (s->a && s->a->next)
		s->a = s->a->next;
	s->a->next = first;
	s->a = second;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	if (s->b && s->b->next)
	{
		first = s->b;
		second = s->b->next;
		while (s->b && s->b->next)
			s->b = s->b->next;
		s->b->next = first;
		s->b = second;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rr(t_data *s)
{
	ra(s);
	rb(s);
	write(1, "rr\n", 3);
}
