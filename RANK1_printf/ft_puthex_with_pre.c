/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_with_pre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:36:59 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 21:48:39 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long nbr)
{
	char	*container;
	int		count;
	int		result;

	container = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		result = ft_puthex_ptr(nbr / 16);
		if (result == -1)
			return (-1);
		count = count + result;
	}
	result = ft_putchar(container[nbr % 16]);
	if (result == -1)
		return (-1);
	return (count + 1);
}

int	ft_puthex_with_pre(unsigned long nbr)
{
	int	result;
	int	hex_prefix;
	int	ptr_prefix;

	if (nbr == 0)
	{
		result = ft_putstr("0x0");
		if (result == -1)
			return (-1);
		return (result);
	}
	else
	{
		hex_prefix = ft_putstr("0x");
		if (hex_prefix == -1)
			return (-1);
		ptr_prefix = ft_puthex_ptr(nbr);
		if (ptr_prefix == -1)
			return (-1);
		result = hex_prefix + ptr_prefix;
		return (result);
	}
}

// int	main(void)
// {
// 	ft_puthex_with_pre(0xffffffffff);
// }
