/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:56:06 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 19:45:30 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

char	*make_stash(int fd, char *str_stash)
{
	char	*buffer;
	int		o_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	o_read = 1;
	while (!ft_strrchr(str_stash, '\n') && o_read != 0)
	{
		o_read = read(fd, buffer, BUFFER_SIZE);
		if (o_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (o_read == 0)
		{
			free(buffer);
			return (str_stash);
		}
		buffer[o_read] = '\0';
		str_stash = ft_strjoin(str_stash, buffer);
	}
	free(buffer);
	return (str_stash);
}

char	*extract_line(char *str_stash)
{
	int		i;
	char	*line;

	if (!str_stash[0])
		return (NULL);
	i = 0;
	while (str_stash[i] && str_stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str_stash[i] && str_stash[i] != '\n')
	{
		line[i] = str_stash[i];
		i++;
	}
	if (str_stash[i] == '\n')
	{
		line[i] = str_stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *str_stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (str_stash[i] && str_stash[i] != '\n')
		i++;
	if (!str_stash[i])
	{
		free(str_stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(str_stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (str_stash[i])
		new_stash[j++] = str_stash[i++];
	new_stash[j] = '\0';
	free(str_stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*str_stash[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD || read(fd, 0, 0) == -1)
		return (NULL);
/*	while (fd)
	{
		str_stash[fd] = make_stash(fd, str_stash[fd]);
		if (!str_stash[fd])
			return (NULL);
	}*/
	str_stash[fd] = make_stash(fd, str_stash[fd]);
	if (!str_stash[fd])
		return (NULL);
	line = extract_line(str_stash[fd]);
	str_stash[fd] = update_stash(str_stash[fd]);
	if (!line)
	{
		free(str_stash[fd]);
		str_stash[fd] = NULL;
	}
	return (line);
}
