/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:05:16 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/13 22:32:07 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_pop(t_stack **head)
{
	t_stack	*node;

	node = *head;
	if (!node)
		return (NULL); // empty list
	if (node->next == node)
	{
		*head = NULL; // only one element
	}
	else
	{
		node->prev->next = node->next; // bypass head
		node->next->prev = node->prev;
		*head = node->next; // move head forward
	}
	node->next = node; // isolate
	node->prev = node;
	return (node);
}
bool	stack_add(t_stack **head, t_stack *node)
{
	if (!node)
		return (false);
	if (!*head)
	{
		*head = node; // node is already circular (1 element)
		return (true);
	}
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;
	*head = node; // node becomes new head
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
		return (false); // 1 element: nothing to do
	b = a->next;
	if (b->next == a)
	{
		// 2 elements: simple swap
		*head = b;
		return (true);
	}
	// 3 or more elements:
	// Before:  prev <-> a <-> b <-> c
	// After:   prev <-> b <-> a <-> c
	a->prev->next = b;
	b->next->prev = a;
	b->prev = a->prev;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	*head = b; // b is new top
	return (true);
}
int	index_of_rank(t_stack *stack, int rank)
{
	const int size = stack_len(stack);
	int i = 0;
	while (i++ < size)
	{
		if (stack->rank == rank)
			return (stack->index);
		stack = stack->next;
	}
	return 0;
}
