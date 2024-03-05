/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:43:58 by asebrani          #+#    #+#             */
/*   Updated: 2024/03/05 04:44:14 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = malloc(j + 1);
	if (str == 0)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char	*str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] <= 13) && (str[i] >= 9)) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - 48);
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		else if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return ((int)(res * sign));
}
