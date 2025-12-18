/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:08:25 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 11:22:38 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_data *data)
{
	if (!data->a)
		return ;
	if (data->a == data->a->prev)
		return ;
	data->a = data->a->prev;
}

void	rrb(t_data *data)
{
	if (!data->b)
		return ;
	if (data->b == data->b->prev)
		return ;
	data->b = data->b->prev;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
