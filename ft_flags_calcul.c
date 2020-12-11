/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:51:36 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 13:18:57 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_list(t_flag *l)
{
	l->etoile_d = 0;
	l->etoile_g = 0;
	l->flag = 'q';
	l->largeur = 0;
	l->precision = -1;
	l->type = 'q';
}

int			avant_prec(t_flag *l, char *str, int i, char *tmp)
{
	if (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			l->flag = '-';
		if (str[i] == '0')
			l->flag = '0';
		i++;
	}
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (str[i] == '*')
	{
		l->etoile_g++;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		tmp = ft_substr(str, i, ft_strlen(str) - i);
		l->largeur = ft_atoi(tmp);
		free(tmp);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

int			apres_prec(t_flag *l, char *str, int i, char *tmp)
{
	i++;
	l->precision++;
	if (str[i] == '*')
	{
		l->etoile_d++;
		i++;
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		tmp = ft_substr(str, i, ft_strlen(str) - i);
		l->precision = ft_atoi(tmp);
		free(tmp);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

t_flag		flags_calcul(char *str)
{
	t_flag		l;
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	init_list(&l);
	i = avant_prec(&l, str, i, tmp);
	if (str[i] == '.')
		i = apres_prec(&l, str, i, tmp);
	l.type = str[i];
	return (l);
}
