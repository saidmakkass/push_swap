/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:48:05 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 11:22:30 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_data *data)
{
	if (!data->a)
		return ;
	if (data->a == data->a->next)
		return ;
	data->a = data->a->next;
}

void	rb(t_data *data)
{
	if (!data->b)
		return ;
	if (data->b == data->b->next)
		return ;
	data->b = data->b->next;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
