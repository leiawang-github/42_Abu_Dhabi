/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_signed_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:03:51 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 20:50:14 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_signed_int(int nbr)
{
	int	count;
	int	result;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		result = ft_putchar('-');
		if (result == -1)
			return (-1);
		count = count + result;
		nbr *= -1;
	}
	result = ft_put_unsigned_int(nbr);
	if (result == -1)
		return (-1);
	count = count + result;
	return (count);
}

// int	main(void)
// {
// 	ft_put_signed_int(-987);
// 	int result;
// 	result = ft_put_signed_int(-1212);
// 	printf("%d", result);
// }
