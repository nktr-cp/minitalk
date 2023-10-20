/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:40:35 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/20 20:40:39 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int	bit;
	static int	c;

	(void)dummy;
	kill(info->si_pid, SIGUSR1);
	if (signum == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
