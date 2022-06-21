/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:06:03 by drakan            #+#    #+#             */
/*   Updated: 2022/02/27 16:41:22 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new_line(char **line, char *buf, int *i)
{
	static char	*str_static;
	char		*tmp;

	if (str_static)
	{
		*line = ft_strdup(str_static);
		free(str_static);
		str_static = NULL;
	}
	else if (!*line)
		*line = ft_strdup("");
	if (*buf)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	tmp = ft_strchr(*line, '\n');
	if (tmp)
	{
		str_static = ft_strdup(tmp + 1);
		*(++tmp) = '\0';
		*i = 0;
	}
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buf;
	int		i;

	i = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (buf)
	{
		while (i > 0)
		{
			i = read (fd, buf, BUFFER_SIZE);
			buf[i] = 0;
			new_line (&line, buf, &i);
		}
	}
	if (!*line)
	{
		free (line);
		line = NULL;
	}
	free (buf);
	return (line);
}
