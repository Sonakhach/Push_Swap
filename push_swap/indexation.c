/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:23:50 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/20 18:24:04 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_a1_to_b(t_data *s)
{
	int	counter;
	int	x;

	counter = 0;
	x = 13;
	if (count_a_stack(s) > 500)
		x = 30;
	while (s->a)
	{
		if (s->a->index <= counter)
		{
			pb(s);
			rb(s);
			counter++;
		}
		else if (s->a->index <= counter + x)
		{
			pb(s);
			counter++;
		}
		else
			ra(s);
	}
}

void	sort_b1_to_a(t_data *s)
{
	int	i;

	i = count_b_stack(s);
	while (i > 0)
	{
		if (part_section_b(s) == 1)
		{
			while (index_max_position_b(s) != 0)
				rb(s);
			pa(s);
		}
		else
		{
			while (index_max_position_b(s) != 0)
				rrb(s);
			pa(s);
		}
		i--;
	}
}

void	alg_a_for_2_elem(t_data *s)
{
	if (s->a->index > s->a->next->index)
		sa(s);
}

void	alg_a_for_3_elem(t_data *s)
{
	t_stack	*tmp;

	tmp = s->a;
	if (tmp->index > tmp->next->index && tmp->index < tmp->next->next->index)
		sa(s);
	else if (tmp->index < tmp->next->index
		&& tmp->index > tmp->next->next->index)
		rra(s);
	else if (tmp->index < tmp->next->index
		&& tmp->next->next->index < tmp->next->index)
	{
		sa(s);
		ra(s);
	}
	else if (tmp->index > tmp->next->index
		&& tmp->next->next->index > tmp->next->index)
		ra(s);
	else if (tmp->index > tmp->next->index
		&& tmp->next->index > tmp->next->next->index)
	{
		sa(s);
		rra(s);
	}	
}
