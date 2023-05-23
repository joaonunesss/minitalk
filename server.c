/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:25:43 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/23 18:49:35 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    sigusr_handler(int signal)
{
    static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x00000001 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main()
{    
    printf("Server PID: %i\n", getpid());
    printf("Waiting messagem from client\n");
    while(1)
    {
        signal(SIGUSR1, sigusr_handler);
        signal(SIGUSR2, sigusr_handler);
        pause();
    }
}