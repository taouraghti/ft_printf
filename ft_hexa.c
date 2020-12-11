/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:52:12 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 13:26:30 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cas_hex_1(t_flag l, va_list ap)
{
	unsigned int	n;
	char			*t;

	n = va_arg(ap, unsigned int);
	if (n == 0 && !l.precision)
		t = ft_strdup("");
	else
		t = ft_hx(n, l.type);
	return (t);
}

char	*cas_hex_2(char *t, t_flag l, char *hexa)
{
	char	*tmp;

	tmp = ft_space(l.precision);
	ft_zero(tmp, ft_strlen(tmp));
	tmp = ft_strcopy(tmp, hexa, ft_strlen(tmp));
	if (l.precision < l.largeur)
		t = ft_strcopy(t, tmp, l.largeur);
	else
	{
		if (l.precision >= ft_abs(l.largeur))
		{
			free(t);
			t = ft_strdup(tmp);
		}
		else
			t = ft_strcopy(t, tmp, l.largeur);
	}
	free(tmp);
	free(hexa);
	return (t);
}

char	*hexa_reinit(t_flag *l, va_list ap, unsigned int *n)
{
	char	*tab;

	if (l->etoile_g)
		l->largeur = va_arg(ap, int);
	if (l->etoile_d)
		l->precision = va_arg(ap, int);
	*n = va_arg(ap, unsigned int);
	if (l->flag == '-' && l->largeur > 0)
		l->largeur = -l->largeur;
	tab = ft_hx(*n, l->type);
	return (tab);
}

char	*ft_hexa(t_flag l, va_list ap)
{
	char			*t;
	unsigned int	n;
	char			*hexa;

	if (!l.etoile_d && !l.etoile_g && !l.largeur
			&& (!l.precision || l.precision == -1) && l.flag == 'q')
		return (cas_hex_1(l, ap));
	hexa = hexa_reinit(&l, ap, &n);
	if ((int)ft_strlen(hexa) > ft_abs(l.largeur) && n != 0)
		l.largeur = ft_strlen(hexa);
	t = ft_space(ft_abs(l.largeur));
	if (l.precision == 0 && n == 0)
	{
		free(hexa);
		return (t);
	}
	if (l.precision >= (int)ft_strlen(hexa))
		return (t = cas_hex_2(t, l, hexa));
	if (l.flag == '0' && l.largeur >= 0 && l.precision < 0)
		ft_zero(t, l.largeur);
	t = ft_strcopy(t, hexa, l.largeur);
	free(hexa);
	return (t);
}
