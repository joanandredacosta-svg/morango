/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:43:20 by jda-cost          #+#    #+#             */
/*   Updated: 2025/10/16 14:56:11 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	envia_char(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(800);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		write(1, "Uso: ./client <PID> <mensagem>\n", 31);
		return (1);
	}
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
		return (write(2, "Erro: PID invalido.\n", 21), 1);
	if (kill(server_pid, 0) == -1)
		return (perror("Erro ao validar PID"), 1);
	i = 0;
	while (argv[2][i])
	{
		envia_char(server_pid, argv[2][i]);
		i++;
	}
	return (envia_char(server_pid, '\0'), 0);
}
