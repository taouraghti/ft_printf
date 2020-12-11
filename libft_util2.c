/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:05:26 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 15:06:44 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_signe(const char *s)
{
	int sig;

	sig = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sig = -1;
	}
	return (sig);
}

int		ft_atoi(const char *s)
{
	int				signe;
	long long int	result;
	long long int	val;

	result = 0;
	val = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\r' || *s == '\v'
				|| *s == '\f' || *s == '\n') && *s)
		s++;
	signe = ft_signe(s);
	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		val = result;
		result = (result * 10) + ((*s - '0') * (signe));
		if (signe == 1 && result < val)
			return (-1);
		if (signe == -1 && result > val)
			return (0);
		s++;
	}
	return (result);
}

char	*ft_alloc(int n, int c)
{
	char	*t;

	if (n < 0)
	{
		if (!(t = malloc(c + 3)))
			return (NULL);
		t[0] = '-';
		t[c + 2] = '\0';
	}
	else
	{
		if (!(t = malloc(c + 2)))
			return (NULL);
		t[c + 1] = '\0';
	}
	return (t);
}

char	*ft_tab(char *t, long long int nbr, int c)
{
	if (nbr < 10)
		t[c] = nbr + '0';
	else
	{
		ft_tab(t, nbr / 10, c - 1);
		t[c] = (nbr % 10) + '0';
	}
	return (t);
}

char	*ft_itoa(int n)
{
	long long int	nbr;
	int				range;
	char			*t;
	int				c;

	range = 1;
	c = 0;
	nbr = n;
	if (n < 0)
		nbr = (-1) * nbr;
	while ((nbr / range) >= 10)
	{
		range = range * 10;
		c++;
	}
	if (!(t = ft_alloc(n, c)))
		return (NULL);
	if (n < 0)
		t = ft_tab(t, nbr, c + 1);
	else
		t = ft_tab(t, nbr, c);
	return (t);
}
