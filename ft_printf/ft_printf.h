/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:15:36 by nboratko          #+#    #+#             */
/*   Updated: 2022/04/28 18:23:37 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../inc/so_long.h"

# ifndef HEX_UP
#  define HEX_UP "0123456789ABCDEF"
# endif

# ifndef HEX_LOW
#  define HEX_LOW "0123456789abcdef"
# endif

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_nbr(long int n);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_pct(void);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char *base);
char	*ft_itoa(int nb);
char	*ft_unsigned_itoa(unsigned int n);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif
