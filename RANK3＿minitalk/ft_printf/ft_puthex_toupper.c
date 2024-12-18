/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_toupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:50:29 by leia              #+#    #+#             */
/*   Updated: 2024/08/11 21:04:45 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_toupper(unsigned int nbr)
{
	char	*container;
	int		count;
	int		result;

	container = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
	{
		result = ft_puthex_toupper(nbr / 16);
		if (result == -1)
			return (-1);
		count = count + result;
	}
	result = ft_putchar(container[nbr % 16]);
	if (result == -1)
		return (-1);
	return (count + 1);
}

// int main(void)
// {
//     ft_puthex_toupper(0xfff123a);
// }
