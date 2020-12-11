/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:49:59 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 15:56:04 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*recur(char *t, unsigned long int n, int i, int j)
{
	if (n < 16)
	{
		if (n > 9)
			t[i] = j + n - 10;
		else
			t[i] = '0' + n;
	}
	else
	{
		recur(t, n / 16, i - 1, j);
		if ((n % 16) > 9)
			t[i] = j + (n % 16) - 10;
		else
			t[i] = '0' + (n % 16);
	}
	return (t);
}

char	*ft_hx(unsigned long int n, char c)
{
	unsigned long int	nb;
	char				*t;
	int					j;
	int					i;

	nb = n;
	j = 0;
	if (c == 'X')
		i = 65;
	if (c == 'x' || c == 'p')
		i = 97;
	while (nb != 0)
	{
		nb = nb / 16;
		j++;
	}
	if (n == 0)
		j++;
	if (!(t = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	t = recur(t, n, j - 1, i);
	t[j] = '\0';
	return (t);
}
