/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:53:53 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/16 00:12:01 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (error(data), 1);
	if (argc == 2)
	{
		data->args = ft_split(argv[1], ' ');
		if (!data->args)
			return (error(data), 1);
		build_stack(data, data->args);
	}
	else
		build_stack(data, argv + 1);
	sort(data);
	clear_data(data);
	return (0);
}
