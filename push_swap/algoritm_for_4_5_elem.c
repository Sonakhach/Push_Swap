/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_for_4_5_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:04:07 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/24 12:11:16 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_a_for_5_elem_inner( t_stack	*tmp, t_data *s)
{
	while (tmp->next->next->next)
		tmp = tmp->next;
	if (tmp->index == sort_max_a(s))
	{
		rra(s);
		rra(s);
		rra(s);
	}
	else if (tmp->next->index == sort_max_a(s))
	{
		rra(s);
		rra(s);
	}
	else if (tmp->next->next->index == sort_max_a(s))
		rra(s);
	pb(s);
}

void	alg_a_for_5_elem(t_data *s)
{
	t_stack	*tmp;

	tmp = s->a;
	if (part_section(s) == 1)
	{
		if (tmp->index == sort_max_a(s))
			pb(s);
		else if (tmp->next->index == sort_max_a(s))
		{
			ra(s);
			pb(s);
		}
	}
	else
		alg_a_for_5_elem_inner(tmp, s);
	alg_a_for_4_elem(s);
	pa(s);
	ra(s);
}

void	alg_a_for_4_elem_inner(t_stack	*tmp, t_data *s)
{
	if (tmp->index == sort_max_a(s))
	{
		rra(s);
		rra(s);
		pb(s);
	}
	else if (tmp->next->index == sort_max_a(s))
	{
		rra(s);
		pb(s);
	}
}

void	alg_a_for_4_elem(t_data *s)
{
	t_stack	*tmp;

	tmp = s->a;
	if (part_section(s) == 1)
	{
		if (tmp->index == sort_max_a(s))
			pb(s);
		else if (tmp->next->index == sort_max_a(s))
		{
			ra(s);
			pb(s);
		}
	}
	else
	{
		while (tmp->next->next)
			tmp = tmp->next;
		alg_a_for_4_elem_inner(tmp, s);
	}	
	alg_a_for_3_elem(s);
	pa(s);
	ra(s);
}

void	fun_sorted_all_alg(t_data	*s)
{
	int	count;	

	count = count_a_stack(s);
	if (count == 5)
		alg_a_for_5_elem(s);
	else if (count == 2)
		alg_a_for_2_elem(s);
	else if (count == 3)
		alg_a_for_3_elem(s);
	else if (count == 4)
		alg_a_for_4_elem(s);
	else if (count >= 6)
	{
		alg_a1_to_b(s);
		s->size = count_b_stack(s);
		sort_b1_to_a(s);
	}
}
