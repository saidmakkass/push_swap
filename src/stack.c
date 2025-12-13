/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:11:32 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/13 23:47:45 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack *stack)
{
	t_stack *head, *tmp;
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

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}
static void build_helper(t_data *data,t_stack *head)
{
	data->a = head;
	data->size_a = stack_len(data->a);
	rank_stack(data->a);
	global_rank_stack(data->a);
}

void	build_stack(t_data *data, char **args)
{
	int		value;
	int		i;
	t_stack	*head;
	t_stack	*current;
	t_stack	*prev;

	check_error(data, args);
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
	build_helper(data, head);
}
