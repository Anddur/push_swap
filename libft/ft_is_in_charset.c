/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:18:27 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/16 18:21:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_is_in_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (c);
		charset++;
	}
	return (0);
}
