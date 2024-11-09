/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:32:08 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 06:29:48 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_base(unsigned long long n, char *base, int *len)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base, len);
	write(1, &base[n % 16], 1);
	(*len)++;
}

int	write_pointer(va_list args)
{
	void	*ptr;
	unsigned long long	addr;
	int		len;

	ptr = va_arg(args, void *);
	addr = (unsigned long long)ptr;
	len = 2;  // pour "0x"
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (3);
	}
	write(1, "0x", 2);  // afficher "0x"
	ft_putnbr_base(addr, "0123456789abcdef", &len);
	return (len);
}
