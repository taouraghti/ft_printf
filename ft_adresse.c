/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:51:20 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/20 16:43:01 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_adresse(t_flag l, va_list ap)
{
	char				*t;
	unsigned long int	n;
	char				*tmp;
	char				*tmp1;

	if (l.etoile_g)
		l.largeur = va_arg(ap, int);
	if (l.flag == '-' && l.largeur > 0)
		l.largeur = -l.largeur;
	n = va_arg(ap, unsigned long int);
	if (n == 0 && !l.precision)
		tmp1 = ft_strdup("");
	else
		tmp1 = ft_hx(n, l.type);
	tmp = ft_strjoin("0x", tmp1);
	free(tmp1);
	if (!l.etoile_d && !l.etoile_g && !l.largeur &&
			(!l.precision || l.precision == -1) && l.flag == 'q')
		return (tmp);
	if ((int)ft_strlen(tmp) > ft_abs(l.largeur))
		l.largeur = ft_strlen(tmp);
	t = ft_space(ft_abs(l.largeur));
	t = ft_strcopy(t, tmp, l.largeur);
	free(tmp);
	return (t);
}
