/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:48:05 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 01:03:06 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (!data->a)
		return ;
	if (data->a == data->a->next)
		return ;
	data->a = data->a->next;
	index_stack(data->a);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	if (!data->b)
		return ;
	if (data->b == data->b->next)
		return ;
	data->b = data->b->next;
	index_stack(data->b);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	if (!data->a && !data->b)
		return ;
	if ((data->b == data->b->next) && (data->a == data->a->next))
		return ;
	if (data->a)
		data->a = data->a->next;
	if (data->b)
		data->b = data->b->next;
	index_stack(data->a);
	index_stack(data->b);
	ft_printf("rr\n");
}
