/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:47:48 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 11:23:02 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_data *data)
{
	t_stack	*node;

	node = stack_pop(&(data->b));
	if (!node)
		return ;
	data->size_b--;
	if (stack_add(&(data->a), node))
		data->size_a++;
}

void	pb(t_data *data)
{
	t_stack	*node;

	node = stack_pop(&(data->a));
	if (!node)
		return ;
	data->size_a--;
	if (stack_add(&(data->b), node))
		data->size_b++;
}
