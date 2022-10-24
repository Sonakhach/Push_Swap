/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_stack1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:42:31 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/20 18:31:48 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max_position(t_data *s)
{
	t_stack	*tmp;
	int		i;

	tmp = s->a;
	i = 1;
	while (tmp->index != sort_max_a(s))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	index_max_position_b(t_data *s)
{
	t_stack	*tmp;
	int		i;

	tmp = s->b;
	i = 0;
	while (tmp->index != sort_max_b(s))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	part_section(t_data *s)
{
	if (index_max_position(s) <= count_a_stack(s) / 2)
		return (1);
	else
		return (2);
}

int	part_section_b(t_data *s)
{
	if (index_max_position_b(s) <= count_b_stack(s) / 2)
		return (1);
	else
		return (2);
}
