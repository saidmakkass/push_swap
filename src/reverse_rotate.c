/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:08:25 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 01:03:33 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (!data->a)
		return ;
	if (data->a == data->a->prev)
		return ;
	data->a = data->a->prev;
	index_stack(data->a);
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	if (!data->b)
		return ;
	if (data->b == data->b->prev)
		return ;
	data->b = data->b->prev;
	index_stack(data->b);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	if (!data->a && !data->b)
		return ;
	if ((data->a == data->a->prev) && (data->b == data->b->prev))
		return ;
	if (data->a)
		data->a = data->a->prev;
	if (data->b)
		data->b = data->b->prev;
	index_stack(data->a);
	index_stack(data->b);
	ft_printf("rrr\n");
}
