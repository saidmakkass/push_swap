/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:06:17 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:00:19 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(t_data *data)
{
	clear_data(data);
	ft_printf("Error\n");
	exit(1);
}

static bool	check_invalid(char **args)
{
	if (!args[0])
		return (true);
	int i, j;
	i = 0;
	while (args[i])
	{
		if (!args[i][0])
			return (true);
		j = 0;
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j]) || args[i][j] == '-'))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_dupe(char **args)
{
	int i, j;
	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
			if (ft_strcmp(args[i], args[j++]) == 0)
				return (true);
		i++;
	}
	return (false);
}

void	check_error(t_data *data, char **args)
{
	if (check_invalid(args) || check_dupe(args))
		error(data);
}