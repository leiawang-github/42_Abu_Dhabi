/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:48:47 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 14:34:20 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_para_len(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar('%');
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_put_signed_int(va_arg(args, int));
	else if (c == 'p')
		len += ft_puthex_with_pre(va_arg(args, unsigned long));
	else if (c == 'u')
		len += ft_put_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(args, int));
	else if (c == 'X')
		len += ft_puthex_toupper(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count = count + ft_para_len(str[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("Hey my char is: %c%c%c%c%c\n", 'q', '1', '\0', '\n', '\t');
// 	printf("Hey my char is: %c%c%c%c%c\n", 'q', '1', '\0', '\n', '\t');

// 	char *str;
// 	str = "{} al$#@@@^&$$^#^@@^$*((&";
// 	// // ft_printf("Hey my char is:%s\n", (char *)NULL);
// 	// // printf("Hey my char is:%s\n", (char *)NULL);

// 	ft_printf("Hey my char is: %p,%s,%s,%c,%d,%i,%x,%X,%%,%u\n", (void *)str,
// 		"Hey there how are you? ", "Nice! ", 'q', 12, 012, 0x987fffff,
// 		0x123897ff, 429496729);
// 	printf("Hey my char is: %p,%s,%s,%c,%d,%i,%x,%X,%%,%u\n", (void *)str,
// 		"Hey there how are you? ", "Nice! ", 'q', 12, 012, 0x987fffff,
// 		0x123897ff, 429496729);
// }