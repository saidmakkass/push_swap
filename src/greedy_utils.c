/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 08:08:23 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 08:23:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_data *data, t_stack *node)
{
	t_stack	*cur;
	int		i;

	cur = data->a;
	i = 0;
	while (i++ < data->size_a)
	{
		if (node->value < cur->value && node->value > cur->prev->value)
			return (cur->index);
		if (node->value < cur->value)
			cur = cur->prev;
		else
			cur = cur->next;
	}
	if (node->value < cur->value)
		while (cur->rank != 0)
			cur = cur->next;
	else
		while (cur->rank != data->size_a - 1)
			cur = cur->next;
	return (cur->index);
}

static int	total_cost(t_greed *greed)
{
	if (greed->dir_a == greed->dir_b)
	{
		if (greed->cost_a >= greed->cost_b)
			return (greed->cost_a + 1);
		else
			return (greed->cost_b + 1);
	}
	else
		return (greed->cost_a + greed->cost_b + 1);
}

int	get_cost(t_data *data, t_greed *greed, int index)
{
	t_stack	*cur;
	int		target;

	ft_bzero(greed, sizeof(t_greed));
	cur = data->b;
	while (cur->index != index)
		cur = cur->next;
	target = get_target(data, cur);
	if (target <= data->size_a - target)
	{
		greed->cost_a = target;
		greed->dir_a = true;
	}
	else
		greed->cost_a = data->size_a - target;
	if (cur->index <= data->size_b - cur->index)
	{
		greed->cost_b = cur->index;
		greed->dir_b = true;
	}
	else
		greed->cost_b = data->size_b - cur->index;
	return (total_cost(greed));
}
