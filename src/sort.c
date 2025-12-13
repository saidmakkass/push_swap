/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:11:44 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/13 23:33:11 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_a(t_stack *stack)
{
	const int	size = stack_len(stack);
	int			i;

	if (size <= 1)
		return (true);
	i = 0;
	while (i++ < size - 1)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_sorted_b(t_stack *stack)
{
	const int	size = stack_len(stack);
	int			i;

	if (size <= 1)
		return (true);
	i = 0;
	while (i++ < size - 1)
	{
		if (stack->value < stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort(t_data *data)
{
	if (is_sorted_a(data->a))
		return ;
	// if (data->size_a <= 10)
	// 	return (small_sort(data));
	small_sort(data);
}
