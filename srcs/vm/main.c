/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:50:22 by briviere          #+#    #+#             */
/*   Updated: 2018/03/14 15:46:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

int		main(int ac, char **av)
{
	int32_t	i;
	t_vm	vm;

	parse_args(&vm, ac, av);
	init_vm(&vm);
	i = -1;
	while (++i < vm.nb_players)
		ft_print("Player #%d: %s\n", i, vm.players[i]->name);
	return (0);
}
