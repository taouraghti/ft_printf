/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:51:08 by aidrissi          #+#    #+#             */
/*   Updated: 2019/12/17 14:11:05 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcopy(char *dest, char *src, int k)
{
	int		i;
	int		j;

	if (k > 0)
		j = k - ft_strlen(src);
	else
		j = 0;
	i = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	return (dest);
}

int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_space(int i)
{
	char	*str;
	int		j;

	j = 0;
	if (i < 0)
		i = -i;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		str[j] = ' ';
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	ft_zero(char *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		s[i] = '0';
		i++;
	}
}

void	lstclear(t_list **lst)
{
	t_list	*list;
	t_list	*preced;

	list = *lst;
	while (list)
	{
		preced = list;
		list = list->next;
		free(preced->content);
		preced->content = NULL;
		free(preced);
	}
	*lst = NULL;
}
