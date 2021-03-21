/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:15:17 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/21 12:24:38 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char **ptr, size_t n, size_t bufflen)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!(temp = (char *)malloc((n) * sizeof(char))))
		return (0);
	while (i < (n - bufflen - 1))
	{
		temp[i] = (*ptr)[i];
		i++;
	}
	temp[i] = 0;
	free(*ptr);
	*ptr = temp;
	return (temp);
}

void	shif_buff(char *buff, size_t pos)
{
	size_t	i;

	i = 1;
	while ((buff)[pos + i])
	{
		(buff)[i - 1] = (buff)[pos + i];
		i++;
	}
	(buff)[i - 1] = 0;
}

int		put_line(char *buff, char **line)
{
	size_t i;
	size_t line_l;

	line_l = *line ? ft_strlen(*line) : 0;
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!(ft_realloc(line, (i + 1 + line_l), i)))
		return (-1);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			(*line)[line_l + i] = 0;
			shif_buff(buff, i);
			return (1);
		}
		(*line)[line_l + i] = buff[i];
		i++;
	}
	(*line)[line_l + i] = 0;
	return (0);
}

int		get_error_fd(char **line)
{
	if (*line)
		free(*line);
	*line = 0;
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static t_blst	*head;
	t_blst			*curr;
	int				read_s;
	int				ctrl;

	if (BUFFER_SIZE <= 0 || (!head && !(head = find_fd(&head, fd))) ||
		!(curr = find_fd(&head, fd)) || !line || fd < 0)
		return (-1);
	(*line) = 0;
	ctrl = 0;
	if ((ctrl = put_line(curr->buff, line)))
		return (ctrl);
	while ((read_s = read(fd, curr->buff, BUFFER_SIZE)) > 0 && ctrl != -1)
	{
		curr->buff[read_s] = 0;
		if ((ctrl = put_line(curr->buff, line)))
			return (ctrl);
	}
	delete_node(&head, curr);
	if (read_s < 0)
		return (get_error_fd(line));
	return (0);
}
