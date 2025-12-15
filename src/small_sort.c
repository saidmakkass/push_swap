/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:31:03 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 02:32:48 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_data *data)
{
	if (is_sorted_b(data->a))
	{
		sa(data);
		rra(data);
	}
	while (!is_sorted_a(data->a))
	{
		if (data->a->value > data->a->next->value
			&& data->a->value < data->a->prev->value)
			sa(data);
		else
			rra(data);
	}
	return ;
}

static void	sort_small(t_data *data)
{
	int	target_index;

	while (!is_sorted_a(data->a) && data->size_a > 3)
	{
		target_index = index_of_rank(data->a, 0);
		while (index_of_rank(data->a, 0) != 0)
		{
			if (target_index <= data->size_a - target_index)
				ra(data);
			else
				rra(data);
		}
		if (!is_sorted_a(data->a))
			pb(data);
	}
	if (!is_sorted_b(data->b))
		sb(data);
	sort_3(data);
	while (data->size_b > 0)
		pa(data);
}

void	small_sort(t_data *data)
{
	if (data->size_a == 2)
		return (sa(data));
	if (data->size_a == 3)
		return (sort_3(data));
	else
		return (sort_small(data));
}
