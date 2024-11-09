/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:55:32 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 06:30:31 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
	//%% a faire
	//norme a faire
int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int len;

    va_start(args, str);
    i = 0;
    len = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'c')
                len = len + write_char(args);
            else if (str[i] == 's')
                len = len + write_string(args);
            else if (str[i] == 'd' || str[i] == 'i')
                len = len + write_number(args);
            else if(str[i] == 'p')
				len = len + write_pointer(args);
			else if (str[i] == 'u')
				len = len + write_unsigned(args);
			else if (str[i] == 'x' || str[i] == 'X')
				len = len + write_hex(args, str[i]);
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

#include <stdio.h>

int main()
{
	unsigned int	x = 42;
    ft_printf("%p", (void *)NULL);
    return 0;
}
