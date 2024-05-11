/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:12:16 by msavelie          #+#    #+#             */
/*   Updated: 2024/05/09 10:12:16 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_input(int fd, char *buf)
{
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buf[0] = '\0';
		return (1);
	}
	return (0);
}

static char	*ft_exit(char *line)
{
	if (line && *line)
		return (line);
	if (line)
		free(line);
	return (NULL);
}

static char	*ft_crealloc(char *buf, size_t len, char *str)
{
	char	*new_str;
	int		i;

	new_str = malloc((len + ft_strlen(str) + 1));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (*buf && len--)
	{
		new_str[i] = *buf;
		i++;
		buf++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

static char	*create_str(char *line, char *buf, char *next_line)
{
	int	bytes;

	bytes = 0;
	if (!*next_line)
	{
		line = ft_crealloc(buf, next_line - buf, line);
		buf[0] = '\0';
	}
	else
	{
		line = ft_crealloc(buf, next_line - buf + 1, line);
		bytes = ft_strlen(next_line + 1) + 1;
	}
	ft_memmove(buf, next_line + 1, bytes);
	if (!line)
		return (ft_exit(line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	int			bytes;

	line = NULL;
	if (check_input(fd, buffer))
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes <= 0)
				return (ft_exit(line));
			buffer[bytes] = '\0';
		}
		next_line = ft_strchr(buffer, '\n');
		if (next_line)
			return (create_str(line, buffer, next_line));
		line = create_str(line, buffer, ft_strchr(buffer, '\0'));
	}
}
