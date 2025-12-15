/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:11:32 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 08:23:50 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!stack)
		return ;
	head = stack;
	while (stack->next != head)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}

int	stack_len(t_stack *stack)
{
	int				len;
	const t_stack	*head = stack;

	if (!stack)
		return (0);
	len = 1;
	while (stack->next != head)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*stack_new(t_data *data, int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (error(data), NULL);
	new->value = value;
	return (new);
}

static void	build_helper(t_data *data, t_stack *head)
{
	int		i;
	int		j;
	t_stack	*tmp;

	data->a = head;
	data->size_a = stack_len(data->a);
	i = 0;
	while (i++ < data->size_a)
	{
		tmp = head->next;
		j = i + 1;
		while (j++ <= data->size_a)
		{
			if (head->value == tmp->value)
				error(data);
			tmp = tmp->next;
		}
		head = head->next;
	}
	rank_stack(data->a);
}

void	build_stack(t_data *data, char **args)
{
	long	value;
	t_stack	*head;
	t_stack	*current;
	t_stack	*prev;

	check_invalid(data, args);
	value = ft_atol(*args++);
	if (value > INT_MAX || value < INT_MIN)
		error(data);
	head = stack_new(data, value);
	prev = head;
	current = head;
	while (*args)
	{
		value = ft_atol(*args++);
		if (value > INT_MAX || value < INT_MIN)
			error(data);
		current = stack_new(data, value);
		current->prev = prev;
		prev->next = current;
		prev = current;
	}
	current->next = head;
	head->prev = current;
	build_helper(data, head);
}
