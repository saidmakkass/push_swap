/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 00:55:38 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/19 15:50:31 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	get_moves(t_data *data)
{
	char	*line;
	t_list	*node;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		node = ft_lstnew(line);
		if (!node)
			error(data);
		ft_lstadd_back(&data->moves, node);
	}
}

void	check_moves(t_data *data)
{
	t_list	*cur;

	cur = data->moves;
	while (cur)
	{
		if (ft_strcmp((char *)(cur->content), "pa\n")
		&& ft_strcmp((char *)(cur->content), "pb\n")
		&& ft_strcmp((char *)(cur->content), "ra\n")
		&& ft_strcmp((char *)(cur->content), "rb\n")
		&& ft_strcmp((char *)(cur->content), "rr\n")
		&& ft_strcmp((char *)(cur->content), "sa\n")
		&& ft_strcmp((char *)(cur->content), "sb\n")
		&& ft_strcmp((char *)(cur->content), "ss\n")
		&& ft_strcmp((char *)(cur->content), "rra\n")
		&& ft_strcmp((char *)(cur->content), "rrb\n")
		&& ft_strcmp((char *)(cur->content), "rrr\n"))
			error(data);
		cur = cur->next;
	}
}

void	run_move(t_data *data, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		pa(data);
	else if (!ft_strcmp(move, "pb\n"))
		pb(data);
	else if (!ft_strcmp(move, "ra\n"))
		ra(data);
	else if (!ft_strcmp(move, "rb\n"))
		rb(data);
	else if (!ft_strcmp(move, "rr\n"))
		rr(data);
	else if (!ft_strcmp(move, "sa\n"))
		sa(data);
	else if (!ft_strcmp(move, "sb\n"))
		sb(data);
	else if (!ft_strcmp(move, "ss\n"))
		ss(data);
	else if (!ft_strcmp(move, "rra\n"))
		rra(data);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(data);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(data);
}

void	checker(t_data *data)
{
	t_list	*cur;

	get_moves(data);
	check_moves(data);
	cur = data->moves;
	while (cur)
	{
		run_move(data, (char *)(cur->content));
		cur = cur->next;
	}
	if (is_sorted_a(data->a) && data->size_b == 0)
	{
		ft_printf("OK\n");
		return ;
	}
	else
		ft_printf("KO\n");
}
