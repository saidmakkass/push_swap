/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:35:43 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 08:14:54 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				rank;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_greed
{
	int				cost_a;
	int				cost_b;
	bool			dir_a;
	bool			dir_b;
}					t_greed;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				size_a;
	int				size_b;
	char			**args;
	t_greed			*greed;
}					t_data;

void				build_stack(t_data *data, char **args);
t_stack				*stack_new(t_data *data, int value);
int					stack_len(t_stack *stack);
void				stack_clear(t_stack *stack);
t_stack				*stack_pop(t_stack **head);
bool				stack_add(t_stack **head, t_stack *node);
bool				stack_swap(t_stack **head);

void				check_invalid(t_data *data, char **args);
void				error(t_data *data);
void				clear_data(t_data *data);

void				pa(t_data *data);
void				pb(t_data *data);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);

void				sort(t_data *data);

void				rank_stack(t_stack *stack);
void				index_stack(t_stack *stack);
bool				is_sorted_a(t_stack *stack);
bool				is_sorted_b(t_stack *stack);
void				small_sort(t_data *data);
int					index_of_rank(t_stack *stack, int rank);

void				big_sort(t_data *data);
void				greedy_insert(t_data *data);
int					get_cost(t_data *data, t_greed *greed, int index);

#endif
