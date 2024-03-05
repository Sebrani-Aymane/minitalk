/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 06:00:36 by asebrani          #+#    #+#             */
/*   Updated: 2024/03/05 05:56:57 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Usage:<server-pid> <string>\n", 30);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (argv[1][0] == '-' || argv[1][0] == '0')
	{
		write(1, "Invalid pid", 11);
		return (0);
	}
	while (*argv[2])
		send_signal(pid, (unsigned char)*argv[2]++);
	send_signal(pid, '\0');
	return (0);
}
