/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:40:31 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 06:53:24 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_hex(unsigned int n, char *base, int *len)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, base, len);
	write(1, &base[n % 16], 1);
	(*len)++;
}

int	write_hex(va_list args, char format)
{
	unsigned int	num;
	int				len;
	char			*base;

	num = va_arg(args, unsigned int);
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr_hex(num, base, &len);
	return (len);
}
