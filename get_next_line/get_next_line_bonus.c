/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:36 by grinella          #+#    #+#             */
/*   Updated: 2023/02/27 16:06:50 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_forline(char *str)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	if (*str == '\0')
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_back(char *backup)
{
	char	*str;
	int		start;
	int		j;

	start = 0;
	while (backup[start] && backup[start] != '\n')
		start++;
	if (backup[start] == '\n')
		start++;
	if (backup[start] == '\0')
	{
		free(backup);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(backup) - start + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (backup[start])
		str[j++] = backup[start++];
	str[j] = '\0';
	free(backup);
	return (str);
}

static char	*read_forline(char *backup, int fd)
{
	int		readed;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	readed = 1;
	while (readed > 0 && ft_putindex(backup, '\n') == -1)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == 0)
			break ;
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*line;

	if (BUFFER_SIZE == 0)
	{
		return (NULL);
	}
	backup[fd] = read_forline(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	line = get_forline(backup[fd]);
	backup[fd] = get_back(backup[fd]);
	return (line);
}
