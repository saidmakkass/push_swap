/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 04:03:13 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 08:22:55 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move(t_data *data)
{
	int		i;
	t_greed	greed;
	int		cost;
	int		min_cost;

	min_cost = INT_MAX;
	i = 0;
	while (i < data->size_b)
	{
		cost = get_cost(data, &greed, i);
		if (cost < min_cost)
		{
			min_cost = cost;
			data->greed->cost_a = greed.cost_a;
			data->greed->cost_b = greed.cost_b;
			data->greed->dir_a = greed.dir_a;
			data->greed->dir_b = greed.dir_b;
		}
		i++;
	}
}

void	move_remaining(t_data *data)
{
	while ((data->greed->cost_a))
	{
		if (data->greed->dir_a)
			ra(data);
		else
			rra(data);
		(data->greed->cost_a)--;
	}
	while ((data->greed->cost_b))
	{
		if (data->greed->dir_b)
			rb(data);
		else
			rrb(data);
		(data->greed->cost_b)--;
	}
}

void	run_move(t_data *data)
{
	if (data->greed->dir_a == data->greed->dir_b)
	{
		while ((data->greed->cost_a) && (data->greed->cost_b))
		{
			if (data->greed->dir_a)
				rr(data);
			else
				rrr(data);
			(data->greed->cost_a)--;
			(data->greed->cost_b)--;
		}
	}
	move_remaining(data);
	pa(data);
}

void	fix_a(t_data *data)
{
	t_stack	*cur;

	cur = data->a;
	while (cur->rank != 0)
		cur = cur->next;
	if (cur->index < data->size_a - cur->index)
	{
		while (data->a->rank != 0)
			ra(data);
	}
	else
	{
		while (data->a->rank != 0)
			rra(data);
	}
}

void	greedy_insert(t_data *data)
{
	data->greed = ft_calloc(1, sizeof(t_greed));
	if (!data->greed)
		error(data);
	while (data->size_b)
	{
		best_move(data);
		run_move(data);
	}
	fix_a(data);
}
