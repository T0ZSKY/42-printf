/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:55:35 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/09 04:41:03 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//--------------------------include------------------------//

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

//--------------------------function------------------------//

int	write_number(va_list args);
int	write_pointer(va_list args);
int	write_unsigned(va_list args);
int write_char(va_list args);
int write_string(va_list args);
int	write_hex(va_list args, char format);
#endif