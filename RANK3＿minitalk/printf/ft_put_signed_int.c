/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_signed_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:03:51 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 14:35:03 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_signed_int(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		count = count + ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		count = count + ft_put_signed_int(nbr / 10);
		count = count + ft_put_signed_int(nbr % 10);
	}
	else
	{
		count = count + ft_putchar((nbr + '0'));
	}
	return (count);
}

// int	main(void)
// {
// 	ft_put_signed_int(-2147483648);
// }
