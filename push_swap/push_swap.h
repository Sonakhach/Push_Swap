/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:52:26 by sokhacha          #+#    #+#             */
/*   Updated: 2022/10/23 19:17:05 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	long int		data;
	int				index;
	struct s_stack	*next;

}t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;	
	int		size;

}t_data;

long int	ft_atoi(char	*str);
char		**ft_split(char	*s, char c);
void		sa(t_data *s);
void		sb(t_data *s);
void		ss(t_data *s);
void		pa(t_data *s);
void		pb(t_data *s);
void		ra(t_data *s);
void		rb(t_data *s);
void		rr(t_data *s);
void		rra(t_data *s);
void		rrb(t_data *s);
void		rrr(t_data *s);
int			letr_error( char **av);
int			duplicat_error(t_data *s);
int			int_rang_error(t_data *s);
t_stack		*inner(int ac, char **av);
void		indexation(t_data *s);
void		alg_a1_to_b(t_data *s);
void		sort_b1_to_a(t_data *s);
void		print_list(t_data *stacks);
int			count_a_stack(t_data *s);
int			count_b_stack(t_data *s);
void		alg_a_for_2_elem(t_data *s);
void		alg_a_for_3_elem(t_data *s);
void		alg_a_for_4_elem(t_data *s);
void		alg_a_for_5_elem(t_data *s);
int			sort_max_a(t_data *s);
int			sort_max_b(t_data *s);
int			index_max_position(t_data *s);
int			index_max_position_b(t_data *s);
int			part_section(t_data *s);
int			part_section_b(t_data *s);
int			sorted(t_data *s);
int			ft_strlen(char *s);
void		ft_strlen_limit(char *s);
void		inner_inner(int *k, char **arr, t_stack	**vars, t_stack	**tmp);
void		fun_sorted_all_alg(t_data *s);
void		fun(char **arr);

#endif
