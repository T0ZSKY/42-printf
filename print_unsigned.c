/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:35:24 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 04:35:31 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_unsigned(unsigned int n, char *base, int *len)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, base, len);
	write(1, &base[n % 10], 1);
	(*len)++;
}

int	write_unsigned(va_list args)
{
	unsigned int	num;
	int				len;

	num = va_arg(args, unsigned int);
	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr_unsigned(num, "0123456789", &len);
	return (len);
}
