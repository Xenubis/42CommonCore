/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:36:54 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/24 16:41:17 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_bis(char *stash, int i)
{
	int		j;
	char	*new;

	i++;
	new = malloc(ft_strlen(stash + i) + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i + j])
	{
		new[j] = stash[i + j];
		j++;
	}
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*clean(char *stash)
{
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	return (clean_bis(stash, i));
}

char	*do_gnl(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int		b;

	b = 1;
	while (b && !new_line(stash))
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[b] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash = do_gnl(fd, stash, buffer);
	if (!stash)
		return (NULL);
	line = extract(stash);
	stash = clean(stash);
	return (line);
}
