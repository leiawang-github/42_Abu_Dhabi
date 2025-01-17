/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:28:08 by leiwang           #+#    #+#             */
/*   Updated: 2024/08/11 22:11:58 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_put_signed_int(int nbr);
int	ft_put_unsigned_int(unsigned int nbr);
int	ft_puthex(unsigned int nbr);
int	ft_puthex_with_pre(unsigned long nbr);
int	ft_puthex_toupper(unsigned int nbr);
int	ft_printf(const char *str, ...);

#endif