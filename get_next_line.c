/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtraore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:00:04 by dtraore           #+#    #+#             */
/*   Updated: 2026/11/21 00:39:17 by dtraore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check(char **strash)
{
	char	*new_line;
	int		count;
	char	*post;
	char	*tmp;

	count = 0;
	if (!*strash || !**strash)
		return (NULL);
	post = ft_strchr(*strash, '\n');
	if (post != NULL)
	{
		while ((*strash)[count] != '\n')
			count++;
		new_line = malloc(count + 2);
		if (!new_line)
			return (NULL);
		count = 0;
		while ((*strash)[count] != '\n')
		{
			new_line[count] = (*strash)[count];
			count++;
		}
		new_line[count] = '\n';
		new_line[count + 1] = '\0';
		tmp = *strash;
		*strash = ft_strdup(post + 1);
		free(tmp);
		return (new_line);
	}
	return (NULL);
}

char	*ft_read(int fd, char **strash)
{
	ssize_t	n_read;
	char	*tmp;
	char	*buff;
	char	*line;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n_read = 1;
	while (n_read > 0)
	{
		line = ft_check(strash);
		if (line != NULL)
		{
			free(buff);
			return (line);
		}
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_read] = '\0';
		if (n_read > 0)
		{
			tmp = *strash;
			*strash = ft_strjoin(*strash, buff);
			free(tmp);
		}
	}
	free(buff);
	if (*strash && **strash != '\0')
	{
		line = ft_strdup(*strash);
		free(*strash);
		*strash = NULL;
		return (line);
	}
	free(*strash);
	*strash = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*strash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!strash)
	{
		strash = ft_strdup("");
		if (!strash)
			return (NULL);
	}
	line = ft_read(fd, &strash);
	if (!line && strash)
	{
		free(strash);
		strash = NULL;
	}
	return (line);
}
