/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:06:17 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/15 06:56:51 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data)
{
	if (data)
		clear_data(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_invalid(t_data *data, char **args)
{
	int	i;
	int	j;

	if (!args[0])
		error(data);
	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
		{
			j++;
			if (!args[i][j])
				error(data);
		}
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]) || args[i][j] == '-'
				|| args[i][j] == '+')
				error(data);
			j++;
		}
		i++;
	}
}
