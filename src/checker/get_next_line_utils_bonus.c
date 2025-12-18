/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:26:59 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 12:54:49 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	line_len(const char *s, char end)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != end)
		i++;
	return (i);
}

bool	found_new_line(char *s)
{
	int	i;

	if (!s)
		return (false);
	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (true);
	return (false);
}

char	*init_line(char **remainder)
{
	char	*line;
	int		i;

	if (!*remainder)
		return (NULL);
	line = malloc(line_len(*remainder, '\0') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while ((*remainder)[i])
	{
		line[i] = (*remainder)[i];
		i++;
	}
	line[i] = '\0';
	clear(remainder);
	return (line);
}

char	*append_buf(char *line, char *buf)
{
	size_t	len_line;
	size_t	len_buf;
	char	*new;
	size_t	i;
	size_t	j;

	len_line = line_len(line, '\0');
	len_buf = line_len(buf, '\0');
	new = malloc(len_line + len_buf + 1);
	if (!new)
		return (clear(&line));
	i = 0;
	j = 0;
	while (j < len_line)
		new[i++] = line[j++];
	j = 0;
	while (j < len_buf)
		new[i++] = buf[j++];
	new[i] = '\0';
	clear(&line);
	return (new);
}
