/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:23:03 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/16 18:53:18 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int len;

	if (!s)
		return (0);
	len = (int)ft_strlen(s);
	write(fd, s, len);
	return (len);
}
