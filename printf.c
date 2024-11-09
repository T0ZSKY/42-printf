/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:55:32 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 06:50:56 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	handle_format(const char *str, va_list args, int *i)
{
	int	len;

	len = 0;
	if (str[*i] == 'c')
		len += write_char(args);
	else if (str[*i] == 's')
		len += write_string(args);
	else if (str[*i] == 'd' || str[*i] == 'i')
		len += write_number(args);
	else if (str[*i] == 'p')
		len += write_pointer(args);
	else if (str[*i] == 'u')
		len += write_unsigned(args);
	else if (str[*i] == 'x' || str[*i] == 'X')
		len += write_hex(args, str[*i]);
	else if (str[*i] == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += handle_format(str, args, &i);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
