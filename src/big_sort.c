/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:48:47 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 08:46:41 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_data *data)
{
	int	chunks;

	while (data->size_a > 2)
	{
		if (data->size_a <= 100)
			chunks = 2;
		else
			chunks = 3;
		if (data->a->rank <= data->size_a / chunks)
			pb(data);
		else
			ra(data);
	}
	greedy_insert(data);
}
