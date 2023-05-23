/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:27:46 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/23 18:55:47 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int main(int ac, char *av[])
{
	int	server_pid;
	char	*msg;
	int	i;
	
	if (ac != 3)
	{
		printf("<server_pid> and <message>\n");  
		return (1);
	}
	else
	{	server_pid = atoi(av[1]);
		msg = av[2];
		i = 0;
		while (msg[i])
		{
			send_bits(server_pid, msg[i]);
			i++;
		}
		send_bits(server_pid, '\n');
	}
}