/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:26:57 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/18 12:54:58 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	*clear(char **ptr)
{
	if (!ptr)
		return (NULL);
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*read_line(int fd, char *line)
{
	char	*buf;
	ssize_t	chars;

	buf = malloc((size_t)2);
	if (!buf)
		return (clear(&line));
	while (!found_new_line(line))
	{
		chars = read(fd, buf, 1);
		if (chars < 0)
			return (clear(&buf), clear(&line));
		if (chars == 0)
			break ;
		buf[chars] = '\0';
		line = append_buf(line, buf);
		if (!line)
			return (clear(&buf));
	}
	clear(&buf);
	return (line);
}

char	*trim_line(char *line, char **remainder)
{
	int		i;
	int		j;
	char	*tmp;
	char	*new_line;

	tmp = line;
	new_line = malloc(line_len(line, '\n') + 2);
	if (!new_line)
		return (clear(&tmp));
	i = -1;
	j = 0;
	while (tmp[j] != '\n')
		new_line[++i] = tmp[j++];
	new_line[++i] = '\n';
	new_line[++i] = '\0';
	*remainder = malloc(line_len(tmp, '\0') - ++j + 1);
	if (!*remainder)
		return (free(new_line), clear(&tmp));
	i = 0;
	while (tmp[j])
		(*remainder)[i++] = tmp[j++];
	(*remainder)[i] = '\0';
	return (clear(&tmp), new_line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0)
		return (NULL);
	line = init_line(&remainder);
	if (!line && remainder)
		return (clear(&remainder));
	line = read_line(fd, line);
	if (!line || line[0] == '\0')
		return (clear(&line));
	if (found_new_line(line))
	{
		line = trim_line(line, &remainder);
		if (!line)
			return (clear(&remainder));
		return (line);
	}
	return (line);
}
