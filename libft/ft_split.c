/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:15:22 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/18 16:45:24 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strdupe(char const *src, char const *end)
{
	char *cpy;
	char *start;

	if (!(cpy = (char *)malloc((end - src + 2) * sizeof(char))))
		return (0);
	start = cpy;
	while (src != end)
		*(cpy++) = *(src++);
	*cpy = '\0';
	return (start);
}

static int			is_sep(char str, char charset)
{
	return (str == charset);
}

static int			final_len(char const *str, char charset,
								char const *end)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
		{
			str++;
			end = 0;
		}
		while (*str && !is_sep(*str, charset))
		{
			end = str;
			str++;
		}
		if (end)
			count++;
	}
	return (count);
}

static char	const	*real_split(char const **str, char c_set,
								char const **begin)
{
	char const *end;

	end = 0;
	while (**str && is_sep(**str, c_set))
	{
		(*str)++;
		*begin = 0;
		end = 0;
	}
	*begin = *str;
	while (**str && !is_sep(**str, c_set))
	{
		end = *str;
		(*str)++;
	}
	return (end);
}

char				**ft_split(char const *str, char c)
{
	int			set_len;
	int			i;
	char		**strs;
	char const	*begin;
	char const	*end;

	if (!str)
		return (0);
	end = 0;
	begin = 0;
	set_len = final_len(str, c, 0);
	if (!(strs = (char **)malloc((set_len + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (*str)
	{
		end = real_split(&str, c, &begin);
		if (end)
			strs[i++] = ft_strdupe(begin, end + 1);
	}
	strs[i] = 0;
	return (strs);
}
