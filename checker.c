/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:13:52 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/19 12:38:51 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_input(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("Error\n", 1);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

t_lst	*ft_lstnew_mod(char *content)
{
	t_lst *res;

	if (!(res = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	res->cont = content;
	res->next = 0;
	return (res);
}

void		ft_lstadd_back_mod(t_lst **alst, char *line)
{
	t_lst *lastelem;

	if (*alst == NULL)
	{
		*alst = ft_lstnew_mod(line);
	}
	else
	{
		lastelem = ft_lstlast(*alst);
		if (lastelem != NULL)
			lastelem->next = ft_lstnew_mod(line);
	}
}

void			check_line(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb") && ft_strcmp(line, "ss")
	&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
	&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr") && ft_strcmp(line, "rra")
	&& ft_strcmp(line, "rrb") && ft_strcmp(line, "rrr"))
	{
		write(1, "Error\n", 6);
		free_exit();
	}
}

void			read_instruction(t_lst **lst, int fd)
{
	int		i;
	char	*line;
	int		ret;
	int		flag;

	i = 1;
	ret = 1;
	flag = 0;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == 0 && flag == 0)
		{
			free(line);
			continue ;
		}
		check_line(line);
		flag = 1;
		i++;
		ft_lstadd_back_mod(lst, line);
	}
}

int		main(int argc, char **argv)
{
	t_stack		stack;
	t_lst		*instr;
	int			temp;
	int			val;

	if (argc == 1)
		exit(0);
	parse_input(argv);
	temp = argc - 1;
	stack = create_stack(temp);
	while (temp > 0)
	{
		val = ft_atoi(argv[temp--]);
		stack_push(&stack, val);
	}
	read_instruction(&instr, 0);
}
