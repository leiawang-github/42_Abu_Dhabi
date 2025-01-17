/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:30:41 by leia              #+#    #+#             */
/*   Updated: 2024/12/18 10:24:06 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	unsigned char	ch;
	int				i;

	while (*message)
	{
		ch = (unsigned char) *message;
		i = -1;
		while (++i < 8)
		{
			if ((ch >> (7 - i)) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
		message++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	int					server_id;

	if (argc == 3)
	{
		server_id = atoi(argv[1]);
		if (!server_id)
		{
			ft_printf("[错误]：输入的 PID 无效。\n");
			return (0);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			ft_printf("Please enter a message\n");
			return (0);
		}
		send_signals(server_id, message);
	}
	else
	{
		ft_printf("Wrong input\n");
		ft_printf("Please enter: PID and a message\n");
	}
	return (0);
}
