/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:37:51 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 04:38:33 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int write_char(va_list args)
{
    char c;

    c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

int write_string(va_list args)
{
    char *str;
    int len;

    str = va_arg(args, char *);
    len = 0;
    if (!str)
        str = "(null)";
    while (str[len])
    {
        write(1, &str[len], 1);
        len++;
    }
    return (len);
}