/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 03:40:46 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 06:51:31 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>  // Pour INT_MIN

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_reverse_str(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static void	ft_itoa_helper(int n, char *str, int len)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
	ft_reverse_str(str, len);
}

int	write_number(va_list args)
{
	int		num;
	char	str[12];
	int		len;

	num = va_arg(args, int);
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	len = ft_numlen(num);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = ft_abs(num);
		len--;
	}
	ft_itoa_helper(num, str, len);
	write(1, str, len);
	return (len);
}

