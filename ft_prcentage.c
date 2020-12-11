/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcentage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:11 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 13:27:32 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prcentage(t_flag l, va_list ap)
{
	char	*t;

	if (l.etoile_g)
		l.largeur = va_arg(ap, int);
	if (l.flag == '-')
		l.largeur = -l.largeur;
	if (!l.largeur)
	{
		if (!(t = malloc(sizeof(char) * 2)))
			return (NULL);
		t[0] = '%';
		t[1] = '\0';
		return (t);
	}
	t = ft_space(ft_abs(l.largeur));
	if (l.flag == '0' && l.largeur > 0)
		ft_zero(t, l.largeur);
	if (l.largeur < 0)
		t[0] = '%';
	else
		t[ft_strlen(t) - 1] = '%';
	return (t);
}
