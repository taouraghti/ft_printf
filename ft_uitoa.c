/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:52:41 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 15:56:27 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ualloc(int c)
{
	char	*t;

	if (!(t = malloc(c + 2)))
		return (NULL);
	t[c + 1] = '\0';
	return (t);
}

char	*ft_utab(char *t, unsigned long int nbr, int c)
{
	if (nbr < 10)
		t[c] = nbr + '0';
	else
	{
		ft_utab(t, nbr / 10, c - 1);
		t[c] = (nbr % 10) + '0';
	}
	return (t);
}

char	*ft_uitoa(unsigned long int n)
{
	unsigned long int		nbr;
	int						range;
	char					*t;
	int						c;

	range = 1;
	c = 0;
	nbr = n;
	while ((nbr / range) >= 10)
	{
		range = range * 10;
		c++;
	}
	if (!(t = ft_ualloc(c)))
		return (NULL);
	t = ft_utab(t, nbr, c);
	return (t);
}
