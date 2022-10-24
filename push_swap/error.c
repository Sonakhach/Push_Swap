/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:07:04 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/23 17:43:24 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicat_error(t_data *s)
{
	int		num;
	t_stack	*tmp;
	t_stack	*tm;
	t_stack	*ptr;

	tmp = s->a;
	ptr = s->a;
	tm = tmp;
	while (tmp)
	{
		num = tmp->data;
		ptr = tmp;
		while (ptr->next)
		{	
			ptr = ptr->next;
			if (ptr->data == num)
				return (1);
		}		
		tmp = tmp->next;
	}
	tmp = tm;
	return (0);
}

int	letr_error(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] != '\0'
					&& (av[i][j] == 32 || (av[i][j] >= 9 && av[i][j] <= 13)))
				j++;
			if (av[i][j] && (av[i][j] == '+' || av[i][j] == '-')
			&& (av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
				return (1);
			else if ((av[i][j]) && (av[i][j] == '+' || av[i][j] == '-'))
				j++;
			while (av[i][j] && av[i][j] >= 48 && av[i][j] <= 57)
				j++;
			if (av[i][j] && av[i][j] != 32)
				return (1);
		}
		i++;
	}
	return (0);
}

int	int_rang_error(t_data *s)
{
	t_stack	*tm;
	t_stack	*tmp;

	tmp = s->a;
	tm = tmp;
	while (tmp)
	{
		if (tmp->data < -2147483648 || tmp->data > 2147483647)
			return (1);
		tmp = tmp->next;
	}
	tmp = tm;
	return (0);
}

int	sorted(t_data *s)
{
	t_stack	*tmp;

	tmp = s->a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
