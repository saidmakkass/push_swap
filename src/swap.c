/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:48:08 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:18:39 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if(stack_swap(&(data->a)))
		write_buf(data, "sa\n");
}

void	sb(t_data *data)
{
	if(stack_swap(&(data->b)))
		write_buf(data, "sb\n");
}
