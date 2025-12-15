/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:47:48 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 01:02:14 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_stack	*node;

	node = stack_pop(&(data->b));
	if (!node)
		return ;
	data->size_b = stack_len(data->b);
	rank_stack(data->b);
	if (stack_add(&(data->a), node))
	{
		ft_printf("pa\n");
		data->size_a = stack_len(data->a);
		rank_stack(data->a);
	}
}

void	pb(t_data *data)
{
	t_stack	*node;

	node = stack_pop(&(data->a));
	if (!node)
		return ;
	data->size_a = stack_len(data->a);
	rank_stack(data->a);
	if (stack_add(&(data->b), node))
	{
		ft_printf("pb\n");
		data->size_b = stack_len(data->b);
		rank_stack(data->b);
	}
}
