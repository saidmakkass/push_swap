/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:48:47 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/19 00:40:51 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_data *data)
{
	int	chunks;

	if (data->size_a <= 100)
		chunks = 2;
	else
		chunks = 3;
	while (data->size_a != 1) 
	{	
		if (data->a->rank <= data->size_a / chunks)
		{
			if (data->size_a >= 60 && data->a->rank <= data->size_a / chunks / 2)
			{
				pb(data);
				rb(data);
			}
			else
				pb(data);
		}
		else
			ra(data);
	}
	greedy_insert(data);
}
