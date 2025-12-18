/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:48:08 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 21:11:09 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (stack_swap(&(data->a)))
		ft_printf("sa\n");
	index_stack(data->a);
}

void	sb(t_data *data)
{
	if (stack_swap(&(data->b)))
		ft_printf("sb\n");
	index_stack(data->b);
}

void	ss(t_data *data)
{
	bool	sa;
	bool	sb;

	sa = stack_swap(&(data->a));
	sb = stack_swap(&(data->b));
	index_stack(data->a);
	index_stack(data->b);
	if (sa || sb)
		ft_printf("ss\n");
}
