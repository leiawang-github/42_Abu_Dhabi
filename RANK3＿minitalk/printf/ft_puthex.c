/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:41:25 by leia              #+#    #+#             */
/*   Updated: 2024/08/10 18:10:32 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr)
{
	char			*container;
	unsigned int	count;

	container = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count = count + ft_puthex(nbr / 16);
	write(1, &container[nbr % 16], 1);
	return (count + 1);
}

// int main(void)
// {
//     ft_puthex(0x6789abc);
// }