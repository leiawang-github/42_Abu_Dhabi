/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_with_pre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:36:59 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/10 18:15:11 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr(unsigned long nbr)
{
	char			*container;
	unsigned int	count;

	container = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count = count + ft_puthex_ptr(nbr / 16);
	write(1, &container[nbr % 16], 1);
	return (count + 1);
}

int	ft_puthex_with_pre(unsigned long nbr)
{
	unsigned int	result;

	if (nbr == 0)
		return (ft_putstr("0x0"));
	else
		result = ft_putstr("0x") + ft_puthex_ptr(nbr);
	return (result);
}

// int main(void)
// {
//     ft_puthex_with_pre(0xffffffffff);
// }
