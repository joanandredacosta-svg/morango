/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:37:54 by jda-cost          #+#    #+#             */
/*   Updated: 2025/10/16 11:09:06 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recebe_bit(int sig)
{
	static unsigned char	c;
	static int				bit_index;

	if (sig == SIGUSR2)
		c |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit_index = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Servidor iniciado. PID = %d\n", pid);
	printf("Aguardando mensagem...\n");
	signal(SIGUSR1, recebe_bit);
	signal(SIGUSR2, recebe_bit);
	while (1)
		pause();
	return (0);
}
