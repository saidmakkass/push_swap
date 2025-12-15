/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:05:16 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 01:05:24 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_pop(t_stack **head)
{
	t_stack	*node;

	node = *head;
	if (!node)
		return (NULL);
	if (node->next == node)
		*head = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*head = node->next;
	}
	node->next = node;
	node->prev = node;
	return (node);
}

bool	stack_add(t_stack **head, t_stack *node)
{
	if (!node)
		return (false);
	if (!*head)
	{
		*head = node;
		return (true);
	}
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;
	*head = node;
	return (true);
}

bool	stack_swap(t_stack **head)
{
	t_stack	*a;
	t_stack	*b;

	if (!head || !*head)
		return (false);
	a = *head;
	if (a->next == a)
		return (false);
	b = a->next;
	if (b->next == a)
	{
		*head = b;
		return (true);
	}
	a->prev->next = b;
	b->next->prev = a;
	b->prev = a->prev;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	*head = b;
	return (true);
}

int	index_of_rank(t_stack *stack, int rank)
{
	const int	size = stack_len(stack);
	int			i;

	i = 0;
	while (i++ < size)
	{
		if (stack->rank == rank)
			return (stack->index);
		stack = stack->next;
	}
	return (0);
}
