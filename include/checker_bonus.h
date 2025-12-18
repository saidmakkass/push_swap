/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:35:43 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 14:29:25 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				size_a;
	int				size_b;
	char			**args;
	t_list			*moves;
}					t_data;

void				build_stack(t_data *data, char **args);
t_stack				*stack_new(t_data *data, int value);
int					stack_len(t_stack *stack);
void				stack_clear(t_stack *stack);
t_stack				*stack_pop(t_stack **head);
bool				stack_add(t_stack **head, t_stack *node);
bool				stack_swap(t_stack **head);
bool				is_sorted_a(t_stack *stack);

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

void				checker(t_data *data);

char				*get_next_line(int fd);
size_t				line_len(const char *s, char end);
void				*clear(char **ptr);
char				*read_line(int fd, char *line);
bool				found_new_line(char *s);
char				*append_buf(char *line, char *buf);
char				*trim_line(char *line, char **remainder);
char				*init_line(char **remainder);

#endif
