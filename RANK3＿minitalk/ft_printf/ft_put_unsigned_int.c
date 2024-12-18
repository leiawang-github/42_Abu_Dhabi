/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:35:14 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 22:12:34 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int nbr)
{
	int	count;
	int	result;

	count = 0;
	if (nbr >= 10)
	{
		result = ft_put_unsigned_int(nbr / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar((nbr % 10) + '0');
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

// int	main(void)
// {
// 	int	result;

// 	ft_put_unsigned_int(987);
// 	result = ft_put_unsigned_int(5);
// 	printf("%d", result);
// }
