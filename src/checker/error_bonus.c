/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:06:17 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/19 00:49:56 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	clear_data(t_data *data)
{
	int	i;

	if (data->a)
		stack_clear(data->a);
	if (data->b)
		stack_clear(data->b);
	if (data->args)
	{
		i = 0;
		while ((data->args)[i])
			free((data->args)[i++]);
		free(data->args);
	}
	if (data->moves)
		ft_lstclear(&data->moves, free);
	free(data);
}

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
