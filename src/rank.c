/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:44:10 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 00:59:20 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_rank(t_stack *stack)
{
	const int	size = stack_len(stack);
	int			i;

	i = 0;
	while (i++ < size)
	{
		stack->rank = 0;
		stack = stack->next;
	}
}

void	index_stack(t_stack *stack)
{
	const int	size = stack_len(stack);
	int			i;

	if (!stack)
		return ;
	i = 0;
	while (i < size)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

void	rank_stack(t_stack *stack)
{
	t_stack		*head;
	t_stack		*current;
	const int	size = stack_len(stack);
	int			i;
	int			j;

	if (!stack)
		return ;
	reset_rank(stack);
	index_stack(stack);
	head = stack;
	i = 0;
	j = 0;
	while (i++ < size)
	{
		current = head;
		j = 0;
		while (j++ < size)
		{
			if (stack->value > current->value)
				stack->rank++;
			current = current->next;
		}
		stack = stack->next;
	}
}
