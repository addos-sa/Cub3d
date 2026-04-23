/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:28:56 by addos-sa          #+#    #+#             */
/*   Updated: 2025/08/04 13:20:59 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		what_to_print(const char src, va_list arg);
int		ft_printf(char const *src, ...);
int		ft_hexa_low(unsigned int s);
int		ft_hexa_upp(unsigned int s);
int		ft_hexa_void(void *s);
int		ft_putnbr_ng(unsigned int n);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_hexalen(unsigned int n);
char	*get_next_line(int fd);
char	*get__line(int fd, char *buffer, char **extra);
void	extrafin(char **line, char **extra);
void	extraent(char **line, char **extra);
size_t	ft_strle(const char *src);
int		stelen_n(char *line);
void	ft_memcp(char *dest, char *src, size_t n);
char	*ft_strjoi(char **s1, char *s2, int tam);

#endif
