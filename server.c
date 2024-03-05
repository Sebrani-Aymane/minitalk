/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 06:17:48 by asebrani          #+#    #+#             */
/*   Updated: 2024/03/05 04:42:19 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_pid(void)
{
	int		pid;
	char	*p_id;
	int		i;

	i = 0;
	pid = getpid();
	p_id = ft_itoa(pid);
	write (1, "The server's pid is : ", 22);
	while (p_id[i] != '\0')
	{
		write(1, &p_id[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (pid);
}

void	handle_signal(int signal, siginfo_t *c_pid, void *walo)
{
	static unsigned char	c;
	static int				i;
	static int				c_pid1;

	if (c_pid1 != c_pid->si_pid)
	{
		c_pid1 = c_pid->si_pid;
		c = 0;
		i = 0;
	}
	c = c | (signal == SIGUSR1);
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
	walo = NULL;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = get_pid();
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = 0;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			return (write (1, "Error has occured ", 18));
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			return (write (1, "Error has occured ", 18));
		usleep(300);
	}
	return (0);
}
