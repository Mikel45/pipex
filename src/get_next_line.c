/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:19:06 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:49 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_line(char *line, char *buf)
{
	if (*line)
	{
		buf[0] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}

char	*get_line(int fd, char *buf, char *line)
{
	int		bytes_count;
	char	*tmp;

	if (ft_strlen(buf) == 0)
		bytes_count = read(fd, buf, BUFFER_SIZE);
	else
		bytes_count = ft_strlen(buf);
	while (bytes_count)
	{
		buf[bytes_count] = '\0';
		tmp = ft_strchr(buf, '\n');
		if (tmp)
		{
			*tmp = '\0';
			line = ft_strjoin_new(line, buf);
			line = ft_strjoin_new(line, "\n");
			ft_strlcpy(buf, ++tmp, BUFFER_SIZE);
			return (line);
		}
		line = ft_strjoin_new(line, buf);
		if (!line)
			return (NULL);
		bytes_count = read(fd, buf, BUFFER_SIZE);
	}
	return (check_line(line, buf));
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = get_line(fd, buf, line);
	return (line);
}
