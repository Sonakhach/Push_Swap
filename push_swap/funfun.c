/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:09:57 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/19 18:45:06 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	write(1, "sa\n", 3);
	if (s->a == NULL || s->a->next == NULL)
		return ;
	first = s->a;
	second = s->a->next;
	first->next = second->next;
	second->next = first;
	s->a = second;
}

void	sb(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	if (s->b == NULL || s->b->next == NULL)
		return ;
	first = s->b;
	second = s->b->next;
	first->next = second->next;
	second->next = first;
	s->b = second;
	write(1, "sb\n", 3);
}

void	ss(t_data *s)
{
	sa(s);
	sb(s);
	write(1, "ss\n", 3);
}

void	pa(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	if (s->b == NULL)
		return ;
	first = s->a;
	second = s->b;
	s->b = s->b->next;
	second->next = first;
	s->a = second;
	write(1, "pa\n", 3);
}

void	pb(t_data *s)
{
	t_stack	*first;
	t_stack	*second;

	if (s->a == NULL)
		return ;
	first = s->b;
	second = s->a;
	s->a = s->a->next;
	second->next = first;
	s->b = second;
	write(1, "pb\n", 3);
}
