/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:35:14 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 14:35:06 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr >= 10)
	{
		count = count + ft_put_unsigned_int(nbr / 10);
		count = count + ft_put_unsigned_int(nbr % 10);
	}
	else
	{
		count = count + ft_putchar((nbr + '0'));
	}
	return (count);
}

// int	main(void)
// {
// 	ft_put_unsigned_int(0);
// }
