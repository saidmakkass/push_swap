/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:11:32 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 16:25:30 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack *stack)
{
	t_stack	*head, *tmp;

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
	stack = stack->next;
	while (stack != head)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

void	build_stack(t_data *data, char **args)
{
	int	value;
	int	i;

	check_error(data, args);
	t_stack *head, *current, *prev;
	i = 0;
	if (args[i])
		head = stack_new(ft_atoi(args[i++]));
	prev = head;
	current = head;
	while (args[i])
	{
		value = ft_atoi(args[i++]);
		current = stack_new(value);
		if (!current)
			stack_clear(data->a);
		current->prev = prev;
		prev->next = current;
		prev = current;
	}
	current->next = head;
	head->prev = current;
	data->a = head;
	data->size_a = stack_len(data->a);
}
