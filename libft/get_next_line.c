/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:30:47 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/21 22:11:12 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup[OPEN_MAX];
	int			read_byte;
	int			idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX || !line)
		return (ERROR);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ERROR);
	/*if (check(fd, line, &buf) == ERROR)
		return (ERROR);*/
	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break;
		buf[read_byte] = 0;
		if (set_backup(&backup[fd], buf))
			return (ERROR);
		idx = ft_strchr((const char *)backup[fd], '\n');
		if (idx >= 0)
		{
			free(buf);
			return (return_line_in_nl(&backup[fd], line, idx));
		}
	}
	free(buf);
	if (read_byte < 0)
		return (ERROR);
	return (return_line(&backup[fd], line));
}

int	check(int fd, char **line, char **buf)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX || !line)
		return (ERROR);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (ERROR);
	return (0);
}

int	set_backup(char **backup_fd, char *buf)
{
	char	*tmp;

	if (*backup_fd)
		tmp = ft_strjoin(*backup_fd, buf);
	else
		tmp = ft_strdup((const char *)buf);
	if (tmp == NULL)
	{
		free(buf);
		return (ERROR);
	}
	if (*backup_fd)
		free(*backup_fd);
	*backup_fd = tmp;
	return (E_O_F);
}
int	return_line(char **backup_fd, char **line)
{
	int	idx_nl;

	idx_nl = ft_strchr((const char *)*backup_fd, '\n');
	if (*backup_fd && (idx_nl >= 0))
		return (return_line_in_nl(backup_fd, line, idx_nl));
	else
	{
		if (*backup_fd)
		{
			*line = *backup_fd;
			*backup_fd = 0;
		}
		else
		{
			*line = ft_strdup((const char *)"");
			if (!(*line))
				return (ERROR);
		}
		return (E_O_F);
	}
}

int	return_line_in_nl(char **backup_fd, char **line, int idx_nl)
{
	char	*tmp;

	(*backup_fd)[idx_nl] = 0;
	/*if (dup_line(&tmp, backup_fd, line))
		return (ERROR);*/
	tmp = ft_strdup((const char *)*backup_fd);
	if (!tmp)
		return (ERROR);
	*line = tmp;
	if ((*backup_fd)[idx_nl + 1])
	{
		tmp = ft_strdup((const char *)(*backup_fd + idx_nl + 1));
		if (!tmp)
		{
			free(*backup_fd);
			*backup_fd = 0;
			return (ERROR);
		}
		free(*backup_fd);
		*backup_fd = tmp;
		return (SUCCUESS);
	}
	if (*backup_fd)
	{
		free(*backup_fd);
		*backup_fd = 0;
	}
	return (SUCCUESS);
}

int	dup_line(char **tmp, char **backup_fd, char **line)
{
	*tmp = ft_strdup((const char *)*backup_fd);
	if (!(*tmp))
		return (ERROR);
	*line = *tmp;
	return (0);
}
