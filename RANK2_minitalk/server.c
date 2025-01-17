/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:12:18 by leia              #+#    #+#             */
/*   Updated: 2024/12/18 13:40:24 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static unsigned char	result = 0;
	static int				bit_count = 0;

	result <<= 1;
	if (signal == SIGUSR2)
		result |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (result == '\0')
		{
			ft_printf("\n");
		}
		else
		{
			ft_printf("%c", result);
		}
		result = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
