/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:11:44 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:25:10 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (true);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (0);
	min = stack->value;
	current = stack->next;
	while (current != stack)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current != stack)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	int		pos;
	t_stack	*current;

	if (!stack)
		return (-1);
	pos = 0;
	current = stack;
	while (current->value != value)
	{
		pos++;
		current = current->next;
		if (current == stack)
			return (-1);
	}
	return (pos);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->value;
	b = data->a->next->value;
	c = data->a->next->next->value;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
	}
	else if (a < b && b > c && a > c)
		rra(data);
}

void	sort_small(t_data *data)
{
	int	min;
	int	pos;
	int	size;

	size = stack_len(data->a);
	while (size > 3)
	{
		min = find_min(data->a);
		pos = get_position(data->a, min);
		if (pos <= size / 2)
		{
			while (data->a->value != min)
				ra(data);
		}
		else
		{
			while (data->a->value != min)
				rra(data);
		}
		pb(data);
		size--;
	}
	if (!is_sorted(data->a))
		sort_three(data);
	while (data->b)
		pa(data);
}

static int	*create_sorted_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	int		j;
	int		tmp;
	t_stack	*current;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = stack;
	i = 0;
	while (i < size)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static int	get_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_large(t_data *data)
{
	int	*sorted;
	int	size;
	int	chunk_size;
	int	pushed;
	int	index;

	size = stack_len(data->a);
	sorted = create_sorted_array(data->a, size);
	if (!sorted)
		return ;
	chunk_size = (size <= 100) ? 20 : 35;
	pushed = 0;
	while (pushed < size - 3)
	{
		index = get_index(sorted, size, data->a->value);
		if (index <= pushed + chunk_size)
		{
			pb(data);
			pushed++;
			if (data->b->next && index <= pushed - chunk_size / 2)
				rb(data);
		}
		else
			ra(data);
	}
	if (!is_sorted(data->a))
		sort_three(data);
	while (data->b)
	{
		int	max;
		int	pos;
		int	len;

		max = find_max(data->b);
		pos = get_position(data->b, max);
		len = stack_len(data->b);
		if (pos <= len / 2)
		{
			while (data->b->value != max)
				rb(data);
		}
		else
		{
			while (data->b->value != max)
				rrb(data);
		}
		pa(data);
	}
	free(sorted);
}

void	sort(t_data *data)
{
	int	size;

	if (!data->a || is_sorted(data->a))
		return ;
	size = stack_len(data->a);
	if (size == 2)
		sa(data);
	else if (size == 3)
		sort_three(data);
	else if (size <= 5)
		sort_small(data);
	else
		sort_large(data);
}