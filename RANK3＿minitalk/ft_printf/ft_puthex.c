/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:41:25 by leia              #+#    #+#             */
/*   Updated: 2024/08/11 21:03:50 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr)
{
	char	*container;
	int		count;
	int		result;

	container = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		result = ft_puthex(nbr / 16);
		if (result == -1)
			return (-1);
		count = count + result;
	}
	result = ft_putchar(container[nbr % 16]);
	if (result == -1)
		return (-1);
	return (count + 1);
}

// int	main(void)
// {
// 	int	result;

// 	ft_puthex(0x6789acd);
// 	write(1, "\n", 1);
// 	result = ft_puthex(0x987abcd);
// 	write(1, "\n", 1);
// 	printf("%d", result);
// }
