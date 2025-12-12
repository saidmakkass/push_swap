/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:47:48 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:21:49 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_stack *node = stack_pop(&(data->b));
	if(!node)
		return;
	if(stack_add(&(data->a), node))
		write_buf(data, "pa\n");
}
void	pb(t_data *data)
{
	t_stack *node = stack_pop(&(data->a));
	if(!node)
		return;
	if(stack_add(&(data->b), node))
		write_buf(data, "pb\n");
}
