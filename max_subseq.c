/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_subseq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:58:48 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/17 16:23:20 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memmove_int(void *dest, const void *src, size_t n)
{
	int		*tmp;
	const int	*s;

	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		tmp = dest;
		s = src;
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dest;
		tmp += n;
		s = src;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
}

int		find_min(int *arr, int len)
{
	int min;
	int i;

	i = 0;
	min = arr[i];
	while (i < len)
	{
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}


void	rotate_arr(int *copy, int len_seq, int min)
{
	int		tmp;

	while (copy[0] != min)
	{
		if (copy[0] != min)
		{
			tmp = copy[0];
			ft_memmove_int(&copy[0], &copy[1], len_seq);
			copy[len_seq - 1] = tmp;
			continue ;
		}
	}
}

int		*calc_lis(int *init_seq, int len_seq, int *max_lis, int *j)
{
	int		i;
	int		*lis;

	if (!(lis = ft_calloc(len_seq, sizeof(int))))
		return (0);
	while (*j < len_seq)
	{
		i = 0;
		while (i < *j)
		{
			if ((init_seq[i] < init_seq[*j]) && lis[i] == lis[*j])
				if (++lis[*j] > *max_lis)
					*max_lis = lis[*j];
			i++;
		}
		(*j)++;
	}
	return (lis);
}

void	take_min(int *copy, int len)
{
	int		min;

	min = find_min(copy, len);
	rotate_arr(copy, len, min);
}

int		*max_subseq(int j, int *lis, int max_lis, int *copy)
{
	int flag;
	int *ret;

	if (!(ret = malloc(sizeof(int) * max_lis)))
		return (NULL);
	flag = 0;
	while (--j >= 0)
	{
		if ((flag == 0 && lis[j] == max_lis) || ((lis[j] == max_lis)
										&& lis[j] < ret[max_lis + 1]))
		{
			ret[max_lis--] = copy[j];
			flag = 1;
		}
	}
	return (ret);
}

int		*calc_max_subseq(t_stack *stack)
{
	int		*copy;
	int		*lis;
	int		max_lis;
	int		j;
	int		*ret;

	j = 0;
	copy = copy_stack(stack);
	take_min(copy, stack->dim);
	lis = calc_lis(copy, stack->dim, &max_lis, &j);
	if (!(ret = malloc(sizeof(int) * max_lis)))
		return (0);
	ret = max_subseq(j, lis, max_lis, copy);
	free(lis);
	return (ret);
}
