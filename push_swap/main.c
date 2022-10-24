/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:30 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/23 19:13:10 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	indexation(t_data *s)
{
	int		i;
	t_stack	*min;
	t_stack	*tmp;
	t_stack	*tm;

	tmp = s->a;
	i = 0;
	tm = s->a;
	while (count_a_stack(s) > i)
	{
		tmp = s->a;
		while (tmp->index != -1)
			tmp = tmp->next;
		min = tmp;
		tmp = s->a;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (min->data > tmp->data && tmp->index == -1)
				min = tmp;
		}
		min->index = i++;
	}
}

void	fun(char **arr)
{
	if (arr)
		free(arr);
}

t_stack	*inner(int ac, char **av)
{
	int		i;
	char	**arr;	
	t_stack	*vars;
	t_stack	*tmp;
	int		k;

	vars = NULL;
	i = 0;
	k = 0;
	if (ac > 1)
	{
		vars = (t_stack *) malloc(sizeof(t_stack));
		tmp = vars;
		while (++i < ac)
		{
			arr = ft_split(av[i], ' ');
			inner_inner(&k, arr, &vars, &tmp);
			fun(arr);
		}
		if (k == 0)
			exit (0);
		vars->next = NULL;
		vars = tmp;
	}
	return (vars);
}

void	inner_inner(int	*k, char **arr, t_stack	**vars, t_stack	**tmp )
{
	int	j;

	j = 0;
	while (arr[j])
	{
		ft_strlen_limit(arr[j]);
		(*vars)->next = (t_stack *)malloc(sizeof(t_stack));
		(*vars) = (*vars)->next;
		(*vars)->data = ft_atoi(arr[j]);
		(*vars)->index = -1;
		if (*k == 0 && arr[j])
		{
			*k = 1;
			free(*tmp);
			(*tmp) = (*vars);
		}
		free(arr[j]);
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	stackk;

	if (ac == 1 || (!*av[1] || !av[1]))
		return (0);
	stackk.b = NULL;
	stackk.a = inner(ac, av);
	indexation(&stackk);
	if ((letr_error(av)) || (duplicat_error(&stackk) == 1)
		|| (int_rang_error(&stackk) == 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!sorted(&stackk))
		return (0);
	fun_sorted_all_alg(&stackk);
	print_list(&stacks);
	return (0);
}

void print_list(t_data *stacks)
{
	t_stack	*ptr;
	t_stack *ptr2;

	ptr = stacks->a;
	ptr2 = stacks->b;
	printf("---stack a---\n");
	while(ptr)
	{
		printf("%ld, ", ptr->data);
		printf("i = %d\n", ptr->index);
		ptr = ptr->next;
	}
	printf("---stack b---\n");
	while(ptr2)
    {
        printf("%ld, ", ptr2->data);
        printf("i = %d\n", ptr2->index);
        ptr2 = ptr2->next;
    }
}
