/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_toupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:50:29 by leia              #+#    #+#             */
/*   Updated: 2024/08/10 15:00:47 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_toupper(unsigned int nbr)
{
	char	*container;
	int		count;

	container = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
		count = count + ft_puthex_toupper(nbr / 16);
	write(1, &container[nbr % 16], 1);
	return (count + 1);
}

// int main(void)
// {
//     ft_puthex_toupper(0xfff123a);
// }
