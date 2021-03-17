/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:07:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/17 12:12:22 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	create_frame(int argc)
{
	t_frame		frame;

	frame.a = create_stack(argc);
	frame.b = create_stack(argc);
	return (frame);
}
