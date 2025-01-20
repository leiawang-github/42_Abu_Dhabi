/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:36:21 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/20 18:09:00 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <ctype.h>

int is_not_dup(int ac, char **av)
{
	int para_size;
	int i;
	int j;

	i = 1;
	para_size = ac - 1;
	while (i < para_size)
	{
		j = i + 1;
		while(j < para_size)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int is_integer(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if (av[i][j] == '-' && av[i][j + 1] != '\0')
            j++;

        while (av[i][j])
        {
            if (!ft_is_digit(av[i][j])) 
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

// int main(int ac, char **av)
// {
//     printf("Result: %d\n", is_not_integer(ac, av));
//     return (0);
// }

int is_within_limits(int ac, char **av) 
{
	(void)av;
	
	if (INT64_MIN < ac -1 && ac - 1 <= INT64_MAX)
		return (0);
	return (1);
}

