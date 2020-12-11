/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_car.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:51:49 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/15 16:26:52 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prem_cas(va_list ap, int *x)
{
	char	*t;
	char	c;

	if (!(t = malloc(sizeof(char) * 2)))
		return (NULL);
	c = va_arg(ap, int);
	t[0] = c;
	if (c == '\0')
		(*x)++;
	t[1] = '\0';
	return (t);
}

char	*ft_car(t_flag l, va_list ap, int *x)
{
	char	*t;
	char	c;

	if (l.etoile_g)
		l.largeur = va_arg(ap, int);
	if (l.flag == '-' && l.largeur > 0)
		l.largeur = -l.largeur;
	if (!l.largeur)
		return (prem_cas(ap, x));
	c = va_arg(ap, int);
	if (c == '\0')
	{
		t = ft_space(ft_abs(l.largeur) - 1);
		if (l.largeur < 0)
			(*x) = -1;
		else
			(*x) = 1;
		return (t);
	}
	t = ft_space(ft_abs(l.largeur));
	if (l.largeur < 0)
		t[0] = c;
	else
		t[ft_strlen(t) - 1] = c;
	return (t);
}
