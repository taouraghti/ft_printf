/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:31 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 13:00:20 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cas_1(va_list ap, t_flag l)
{
	int		n;
	char	*t;

	n = va_arg(ap, int);
	if (n == 0 && !l.precision)
		t = ft_strdup("");
	else
		t = ft_itoa(n);
	return (t);
}

char		*ft_neg(char *t, t_flag l, int x)
{
	int		i;
	int		k;

	i = 0;
	if (l.largeur < l.precision && x == 1)
	{
		t[0] = '-';
		i++;
		while (t[i] == '0')
			i++;
		t[i] = '0';
	}
	else
	{
		while (t[i] == ' ')
			i++;
		k = i;
		while (t[i] == '0')
			i++;
		t[i] = '0';
		t[k] = '-';
	}
	return (t);
}

char		*cas_2(char *t, t_flag l, int n, char *tmp1)
{
	char	*tmp;

	if (n >= 0)
		tmp = ft_space(l.precision);
	else
		tmp = ft_space(l.precision + 1);
	ft_zero(tmp, ft_strlen(tmp));
	tmp = ft_strcopy(tmp, tmp1, ft_strlen(tmp));
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
	if (n < 0)
		t = ft_neg(t, l, 1);
	free(tmp);
	free(tmp1);
	return (t);
}

char		*nouveau_list(t_flag *l, va_list ap, int *n)
{
	char	*tab;

	if (l->etoile_g)
		l->largeur = va_arg(ap, int);
	if (l->etoile_d)
		l->precision = va_arg(ap, int);
	if (l->flag == '-' && l->largeur > 0)
		l->largeur = -l->largeur;
	*n = va_arg(ap, int);
	tab = ft_itoa(*n);
	return (tab);
}

char		*ft_entier(t_flag l, va_list ap)
{
	char	*t;
	int		n;
	char	*tmp1;

	if (!l.etoile_d && !l.etoile_g && !l.largeur
			&& (!l.precision || l.precision == -1) && l.flag == 'q')
		return (t = cas_1(ap, l));
	tmp1 = nouveau_list(&l, ap, &n);
	if ((int)ft_strlen(tmp1) > ft_abs(l.largeur) && n != 0)
		l.largeur = ft_strlen(tmp1);
	t = ft_space(ft_abs(l.largeur));
	if (l.precision == 0 && n == 0)
	{
		free(tmp1);
		return (t);
	}
	if (l.precision >= (int)ft_strlen(tmp1))
		return (t = cas_2(t, l, n, tmp1));
	if (l.flag == '0' && l.largeur >= 0 && l.precision < 0)
		ft_zero(t, l.largeur);
	t = ft_strcopy(t, tmp1, l.largeur);
	if (n < 0 && l.largeur > (int)ft_strlen(tmp1))
		t = ft_neg(t, l, 0);
	free(tmp1);
	return (t);
}
