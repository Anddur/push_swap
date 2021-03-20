/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:26:57 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/20 16:38:56 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_success(void)
{
	write(1, GRN, 5);
	write(1, "                      ", 37);
	write(1, "                                                   \n", 52);
	write(1, "                      ", 37);
	write(1, "                              $$$                  \n", 52);
	write(1, "                      ", 37);
	write(1, "                             $$$                   \n", 52);
	write(1, "                      ", 37);
	write(1, "                  $$$       $$$                    \n", 52);
	write(1, "                      ", 37);
	write(1, "                   $$$     $$$                     \n", 52);
	write(1, "                      ", 37);
	write(1, "                    $$$   $$$                      \n", 52);
	write(1, "                      ", 37);
	write(1, "                     $$$$$$$                       \n", 52);
	write(1, "                      ", 37);
	write(1, "                      $$$$$                        \n", 52);
	write(1, "                      ", 37);
	write(1, "                                                   \n", 52);
	write(1, "                      ", 37);
	write(1, NRM, 4);
}

void	print_fail(void)
{
	write(1, RED, 5);
	write(1, "                      ", 37);
	write(1, "                                                \n", 49);
	write(1, "                      ", 37);
	write(1, "                  xxxx    xxxx                  \n", 49);
	write(1, "                      ", 37);
	write(1, "                   xxxx  xxxx                   \n", 49);
	write(1, "                      ", 37);
	write(1, "                    xxxxxxxx                    \n", 49);
	write(1, "                      ", 37);
	write(1, "                     xxxxxx                     \n", 49);
	write(1, "                      ", 37);
	write(1, "                    xxxxxxxx                    \n", 49);
	write(1, "                      ", 37);
	write(1, "                   xxxx  xxxx                   \n", 49);
	write(1, "                      ", 37);
	write(1, "                  xxxx    xxxx                  \n", 49);
	write(1, "                      ", 37);
	write(1, "                                                \n", 49);
	write(1, NRM, 4);
}
