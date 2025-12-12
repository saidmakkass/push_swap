/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:53:53 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:14:00 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_data(t_data *data)
{
	stack_clear(data->a);
	stack_clear(data->b);
	free(data->buf);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int i = 0;

	if (argc < 2)
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		build_stack(data, argv);
		while(argv[i])
			free(argv[i++]);
		free(argv);
	}
	else
		build_stack(data, argv+1);
	sort(data);
	print_buf(data);
	clear_data(data);
	return (0);
}
