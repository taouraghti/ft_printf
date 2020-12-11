/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:52:21 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/16 16:50:30 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reinit(t_flag *l, va_list ap)
{
	char	*t;

	if (l->etoile_g)
		l->largeur = va_arg(ap, int);
	if (l->etoile_d)
		l->precision = va_arg(ap, int);
	if (l->flag == '-' && l->largeur > 0)
		l->largeur = -l->largeur;
	t = ft_space(l->largeur);
	return (t);
}

char	*dern_cas(t_flag l, va_list ap)
{
	char	*t;
	char	*tmp1;
	char	*tmp;

	t = reinit(&l, ap);
	tmp1 = va_arg(ap, char*);
	if (tmp1 == NULL)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(tmp1);
	if (l.precision >= 0 && l.precision < (int)ft_strlen(tmp))
	{
		tmp1 = tmp;
		tmp = ft_substr(tmp, 0, l.precision);
		free(tmp1);
	}
	if (ft_strlen(t) >= ft_strlen(tmp))
		t = ft_strcopy(t, tmp, l.largeur);
	else
	{
		free(t);
		t = ft_strdup(tmp);
	}
	free(tmp);
	return (t);
}

char	*ft_string(t_flag l, va_list ap)
{
	char	*t;
	char	*tmp1;

	if (!l.etoile_d && !l.etoile_g && !l.largeur
			&& l.precision == -1 && l.flag == 'q')
	{
		tmp1 = va_arg(ap, char*);
		if (tmp1 == NULL)
			t = ft_strdup("(null)");
		else
			t = ft_strdup(tmp1);
	}
	else if (!l.etoile_d && !l.etoile_g && !l.largeur
			&& !l.precision && l.flag == 'q')
		t = ft_strdup("");
	else
		t = dern_cas(l, ap);
	return (t);
}
