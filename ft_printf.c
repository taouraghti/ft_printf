/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:52 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/21 16:52:10 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type(va_list ap, t_flag l, int *x)
{
	if (l.type == 's')
		return (ft_string(l, ap));
	if (l.type == 'c')
		return (ft_car(l, ap, x));
	if (l.type == 'd' || l.type == 'i')
		return (ft_entier(l, ap));
	if (l.type == 'u')
		return (ft_unsint(l, ap));
	if (l.type == 'X' || l.type == 'x')
		return (ft_hexa(l, ap));
	if (l.type == 'p')
		return (ft_adresse(l, ap));
	if (l.type == '%')
		return (ft_prcentage(l, ap));
	return (NULL);
}

int		affichage(char *t, int k, int x)
{
	if (x == 1 || x == -1)
	{
		if (x == 1)
		{
			ft_putstr_fd(t, 1);
			write(1, "\0", 1);
		}
		else if (x == -1)
		{
			write(1, "\0", 1);
			ft_putstr_fd(t, 1);
		}
		x = 0;
		k++;
	}
	else
		ft_putstr_fd(t, 1);
	k = k + ft_strlen(t);
	free(t);
	return (k);
}

int		fonct(const char *str, int *i, va_list ap, int k)
{
	char		*tab;
	t_flag		l;
	int			j;
	char		*t;
	int			x;

	j = *i;
	x = 0;
	if (str[*i] == '%')
		(*i)++;
	while (str[*i] != 'c' && str[*i] != 's' && str[*i] != 'p' && str[*i] != 'd'
			&& str[*i] != 'i' && str[*i] != 'u' && str[*i] != 'x'
			&& str[*i] != 'X' && str[*i] != '%' && str[*i])
		(*i)++;
	(*i)++;
	tab = ft_substr(str, j + 1, (*i) - j);
	l = flags_calcul(tab);
	free(tab);
	t = ft_type(ap, l, &x);
	return (affichage(t, k, x));
}

int		ft_initlist(const char *str, int *i, int k)
{
	int		j;
	char	*tmp;

	j = *i;
	while (str[*i] != '%' && str[*i])
		(*i)++;
	tmp = ft_substr(str, j, (*i) - j);
	ft_putstr_fd(tmp, 1);
	k = k + ft_strlen(tmp);
	free(tmp);
	tmp = NULL;
	return (k);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			k;

	i = 0;
	k = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			k = ft_initlist(str, &i, k);
		else if (str[i] && str[i] == '%')
			k = fonct(str, &i, ap, k);
	}
	va_end(ap);
	return (k);
}
