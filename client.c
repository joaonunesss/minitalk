/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:27:46 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/29 10:54:16 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	send_bits(int server_pid, int c)
{
	int	bit_client;

	bit_client = 0;
	while (bit_client < 8)
	{
		if ((c & (0x01 << bit_client)))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit_client++;
	}
}

int	main(int ac, char *av[])
{
	int	server_pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("./client <server_pid>  <message to write in server>\n");
		return (1);
	}
	else
	{
		i = -1;
		server_pid = atoi(av[1]);
		while (av[2][++i])
			send_bits(server_pid, av[2][i]);
		send_bits(server_pid, '\n');
	}
}
