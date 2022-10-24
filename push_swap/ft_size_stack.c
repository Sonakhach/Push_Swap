/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:32:48 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/20 15:45:17 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_a_stack(t_data *s)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = s->a;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	count_b_stack(t_data *s)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = s->b;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	sort_max_b(t_data *s)
{
	t_stack		*tmp;
	t_stack		*tm;
	long int	max;

	tmp = s->b;
	tm = tmp;
	max = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (max < tmp->index)
			max = tmp->index;
	}
	tmp = tm;
	return (max);
}

int	sort_max_a(t_data *s)
{
	t_stack		*tmp;
	t_stack		*tm;
	long int	max;

	tmp = s->a;
	tm = tmp;
	max = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (max < tmp->index)
			max = tmp->index;
	}
	tmp = tm;
	return (max);
}
