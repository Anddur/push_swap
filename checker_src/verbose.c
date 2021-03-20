/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:38:16 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 16:53:53 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			int_dimension(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void		print_head(void)
{
	write(1, "                                                  ", 50);
	write(1, CYN"  STACK A  "NRM, 20);
	write(1, "|", 1);
	write(1, MAG"  STACK B  "NRM, 20);
	write(1, "\n", 1);
	write(1, "                                                  ", 50);
	write(1, "----------- -----------\n", 24);
}

void		print_a(int i, t_frame frame)
{
	char *itoa;

	itoa = ft_itoa(frame.a.cont[i][0]);
	write(1, "                                                 |", 53);
	write(1, CYNBLK, 10);
	int_dimension(frame.a.cont[i][0]);
	int_dimension(frame.b.cont[i][0]);
	if (i < frame.a.dim)
	{
		write(1, "          ", 10 - int_dimension(frame.a.cont[i][0]));
		write(1, itoa,
				int_dimension(frame.a.cont[i][0]));
		write(1, " ", 1);
	}
	else
		write(1, "           ", 11);
	free(itoa);
}

void		print_b(int i, t_frame frame)
{
	char *itoa;

	itoa = ft_itoa(frame.b.cont[i][0]);
	write(1, MAGWHT, 10);
	if (i < frame.b.dim)
	{
		write(1, " ", 1);
		write(1, itoa,
				int_dimension(frame.b.cont[i][0]));
		write(1, "           ", 10 - int_dimension(frame.b.cont[i][0]));
	}
	else
		write(1, "           ", 11);
	write(1, NRM"|", 5);
	free(itoa);
}

void		print_stack(t_frame frame)
{
	int i;

	write(1, "\033[2J", 4);
	i = 0;
	print_head();
	i = 0;
	while (i <= frame.a.dim + frame.b.dim - 1)
	{
		print_a(i, frame);
		write(1, NRM, 4);
		write(1, "|", 1);
		print_b(i, frame);
		write(1, NRM, 4);
		write(1, "\n", 1);
		write(1, "                                                  ", 50);
		write(1, "-----------------------\n", 24);
		i++;
	}
	while (i++ < 20)
		write(1, "\n", 1);
}
