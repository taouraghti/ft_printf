/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:59 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 15:55:28 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;
typedef struct	s_flag
{
	char		flag;
	int			largeur;
	int			precision;
	char		type;
	int			etoile_d;
	int			etoile_g;
}				t_flag;
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strcopy(char *dest, char *src, int k);
void			ft_zero(char *s, int n);
int				ft_abs(int n);
char			*ft_uitoa(unsigned long int n);
char			*ft_hx(unsigned long int n, char c);
char			*ft_space(int i);
t_flag			flags_calcul(char *str);
char			*ft_adresse(t_flag l, va_list ap);
char			*ft_car(t_flag l, va_list ap, int *k);
char			*ft_entier(t_flag l, va_list ap);
char			*ft_hexa(t_flag l, va_list ap);
char			*ft_string(t_flag l, va_list ap);
char			*ft_unsint(t_flag l, va_list ap);
void			init_list(t_flag *l);
void			init_list(t_flag *l);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
char			*ft_space(int i);
int				ft_atoi(const char *s);
char			*ft_strdup(const char *s1);
void			ft_putstr_fd(char *s, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_type(va_list ap, t_flag l, int *x);
int				fonct(const char *str, int *i, va_list ap, int k);
int				ft_initlist(const char *str, int *i, int k);
char			*ft_prcentage(t_flag l, va_list ap);
int				ft_printf(const char *str, ...);
void			lstclear(t_list **lst);
#endif
