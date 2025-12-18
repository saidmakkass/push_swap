/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:48:08 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 11:22:18 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_data *data)
{
	stack_swap(&(data->a));
}

void	sb(t_data *data)
{
	stack_swap(&(data->b));
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
