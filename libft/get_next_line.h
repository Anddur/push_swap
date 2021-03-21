/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:15:56 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/21 12:24:23 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# define BUFFER_SIZE 1

typedef struct	s_blst
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	struct s_blst	*next;
}				t_blst;

int				get_next_line(int fd, char **line);
t_blst			*find_fd(t_blst **head, int fd);
char			*ft_realloc(char **ptr, size_t n, size_t bufflen);
int				put_line(char *buff, char **line);
t_blst			*new_node(int fd);
t_blst			*find_fd(t_blst **head, int fd);
void			delete_node(t_blst **head, t_blst *to_del);
#endif
