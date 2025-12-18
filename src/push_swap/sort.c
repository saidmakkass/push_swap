/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:11:44 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 23:37:21 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	if (is_sorted_a(data->a))
		return ;
	if (data->size_a <= 10)
		return (small_sort(data));
	big_sort(data);
}
