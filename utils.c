/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:38:00 by asebrani          #+#    #+#             */
/*   Updated: 2024/03/05 05:50:24 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		num;
	int		len;
	char	*str;

	num = n;
	len = get_num_len(num);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (len)
	{
		str[--len] = (num % 10) * (1 - 2 * (num < 0)) + '0';
		num /= 10;
	}
	*str = *str - 3 * (n < 0);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count * size) < count && (count * size) < size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
