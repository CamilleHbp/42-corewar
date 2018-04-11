/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:17:37 by cbaillat          #+#    #+#             */
/*   Updated: 2018/04/11 10:20:21 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <fcntl.h>

static int	parse_arg(t_vm *vm, char **av, int i)
{
	static size_t	i_fd;

	if (ft_strequ(av[i], "--ncurses") || ft_strequ(av[i], "-n"))
		vm->flags |= (1 << VISUAL);
	else if (ft_strequ(av[i], "--dump") || ft_strequ(av[i], "-d"))
	{
		if (av[i + 1])
			vm->dump = ft_atoi64(av[++i]);
		if (vm->dump <= INT32_MAX && vm->dump > 0)
			vm->flags |= (1 << DUMP);
	}
	else if (ft_strequ(av[i], "--verbose") || ft_strequ(av[i], "-v"))
	{
		if (av[i + 1] && ft_strisnum(av[i + 1]))
			vm->verbose = ft_atoi(av[++i]);
		else
			vm->verbose = 1;
	}
	else if ((fds[i_fd++] = open(av[i], O_RDONLY)) < 0)
	{
		ft_putendl_fd("invalid file", 2);
		return (ERROR);
	}
	return (SUCCESS);
}

int			*parse_args(t_vm *vm, int ac, char **av)
{
	int		i;
	size_t	i_fd;
	int		*fds;

	i = 1;
	if (!(fds = ft_memalloc(sizeof(int) * ac)))
		return (NULL);
	while (i < ac)
	{
		if (parse_arg(vm, av, i) == ERROR)
			return (NULL);
		++i;
	}
	vm->nb_players = i_fd;
	return (fds);
}
