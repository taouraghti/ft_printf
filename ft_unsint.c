/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:21 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 13:29:28 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reinit(t_flag *l, va_list ap, unsigned int *n)
{
	char	*t;
	char	*tmp1;

	if (l->etoile_g)
		l->largeur = va_arg(ap, int);
	if (l->etoile_d)
		l->precision = va_arg(ap, int);
	if (l->flag == '-' && l->largeur > 0)
		l->largeur = -l->largeur;
	*n = va_arg(ap, unsigned int);
	tmp1 = ft_uitoa(*n);
	if ((int)ft_strlen(tmp1) > ft_abs(l->largeur) && n != 0)
		l->largeur = ft_strlen(tmp1);
	t = ft_space(l->largeur);
	free(tmp1);
	return (t);
}

char	*u_dern_cas(t_flag l, char *tmp1, char *t)
{
	char	*tmp;

	tmp = ft_space(l.precision);
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
	free(tmp);
	free(tmp1);
	return (t);
}

char	*ft_unsint(t_flag l, va_list ap)
{
	char			*t;
	unsigned int	n;
	char			*tmp1;

	if (!l.etoile_d && !l.etoile_g && !l.largeur
			&& (!l.precision || l.precision == -1) && l.flag == 'q')
	{
		n = va_arg(ap, unsigned int);
		if (n == 0 && !l.precision)
			t = ft_strdup("");
		else
			t = ft_uitoa(n);
		return (t);
	}
	t = ft_reinit(&l, ap, &n);
	tmp1 = ft_uitoa(n);
	if (l.precision == 0 && n == 0)
		return (t);
	if (l.precision >= (int)ft_strlen(tmp1))
		return (t = u_dern_cas(l, tmp1, t));
	if (l.flag == '0' && l.largeur >= 0 && l.precision < 0)
		ft_zero(t, l.largeur);
	t = ft_strcopy(t, tmp1, l.largeur);
	free(tmp1);
	return (t);
}
