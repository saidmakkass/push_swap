/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:48:05 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:24:41 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (data->a == data->a->next)
		return ;
	data->a = data->a->next;
	write_buf(data, "ra\n");
}
void	rb(t_data *data)
{
	if (data->b == data->b->next)
		return ;
	data->b = data->b->next;
	write_buf(data, "rb\n");
}
void	rra(t_data *data)
{
	if (data->a == data->a->prev)
		return ;
	data->a = data->a->prev;
	write_buf(data, "rra\n");
}
void	rrb(t_data *data)
{
	if (data->b == data->b->prev)
		return ;
	data->b = data->b->prev;
	write_buf(data, "rrb\n");
}
