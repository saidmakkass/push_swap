/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:08:25 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/13 18:38:53 by smakkass         ###   ########.fr       */
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
	write_buf(data, "rra\n");
}
void	rrb(t_data *data)
{
	if (!data->b)
		return ;
	if (data->b == data->b->prev)
		return ;
	data->b = data->b->prev;
	index_stack(data->b);
	write_buf(data, "rrb\n");
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
	write_buf(data, "rrr\n");
}
