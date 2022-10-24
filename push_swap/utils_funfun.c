/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funfun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:07:56 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/19 18:27:17 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *s)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (s->a == NULL || s->a->next == NULL)
		return ;
	first = s->a;
	while (s->a->next)
	{
		second = s->a;
		last = s->a->next;
		s->a = s->a->next;
	}
	s->a = last;
	last->next = first;
	second->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_data *s)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (s->b == NULL || s->b->next == NULL)
		return ;
	first = s->b;
	while (s->b->next)
	{
		second = s->b;
		last = s->b->next;
		s->b = s->b->next;
	}
	s->b = last;
	last->next = first;
	second->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *s)
{
	rra(s);
	rrb(s);
	write(1, "rrr\n", 4);
}

void	ft_strlen_limit(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		exit (1);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_strlen(s + i) > 16)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
