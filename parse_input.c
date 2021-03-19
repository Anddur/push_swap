/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:46:44 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 19:08:49 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_correct(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ' && !ft_isdigit(argv[i]) && argv[i] != '-')
			exit_error();
		if (argv[i] == '-' && (!argv[i + 1] || !ft_isdigit(argv[i + 1])))
			exit_error();
		i++;
	}
	if (argv[i] == 'u')
		exit_error();
	return (1);
}

int		is_string(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
		if (argv[i++] == ' ')
			return (1);
	return (0);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	if (!s2)
		return (NULL);
	i = 0;
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = 0;
	free(s1);
	return (join);
}

void		check_repeat(char **arg)
{
	int i;
	int j;

	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (!ft_strcmp(arg[j], arg[i]))
				exit_error();
			j++;
		}
		i++;
	}
}

char		**parse_input(char **argv, int argc)
{
	char	*arg;
	int		i;
	char	**split;

	if (argc < 2)
		exit_error();
	i = 1;
	while (argv[i] && is_correct(argv[i]))
	{
		arg = ft_strjoin_mod(arg, argv[i]);
		arg = ft_strjoin_mod(arg, " ");
		i++;
	}
	split = ft_split(arg, ' ');
	free(arg);
	check_repeat(split);
	return (split);
}
