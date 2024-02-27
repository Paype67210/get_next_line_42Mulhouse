/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:54:04 by pdeson            #+#    #+#             */
/*   Updated: 2023/11/15 11:50:33 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_before_newline(const char *s)
{
	char	*buffer;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	buffer = ft_memset(i + 1, sizeof * buffer);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		buffer[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		buffer[i] = s[i];
		i++;
	}
	return (buffer);
}

char	*get_after_newline(const char *s)
{
	char	*buffer;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	buffer = ft_memset((j - i) + 1, sizeof * buffer);
	if (!buffer)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		buffer[j] = s[i + j];
		j++;
	}
	return (buffer);
}

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free_strs(keep, 0, 0);
		*keep = ft_strjoin(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*keep))
			break ;
	}
	ft_free_strs(&buf, 0, 0);
}

char	*ft_parse_line(char **keep, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*keep);
	ft_free_strs(keep, 0, 0);
	*keep = get_after_newline(*tmp);
	line = get_before_newline(*tmp);
	ft_free_strs(tmp, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	ft_read_line(fd, &keep, &tmp);
	if (keep != NULL && *keep != '\0')
		line = ft_parse_line(&keep, &tmp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&keep, &line, &tmp);
		return (NULL);
	}
	return (line);
}
