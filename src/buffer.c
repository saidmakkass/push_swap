/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:34:59 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/12 18:16:37 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void write_buf(t_data *data,const char *s)
{
	char *tmp;
	if (!data->buf)
		data->buf = ft_strdup("\0");
	if (!data->buf)
		error(data);
	tmp = data->buf;
	data->buf = ft_strjoin(tmp, s);
	free(tmp);
}

void print_buf(t_data *data)
{
	if(!data->buf)
		return ;
	ft_printf("%s", data->buf);
}