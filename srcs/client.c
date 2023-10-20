/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:40:47 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/20 20:47:42 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_success;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		g_success = 1;
}

void	timeout(void)
{
	long	time;

	time = 0;
	while (g_success == 0)
	{
		usleep(1);
		time++;
		if (time >= 100000)
			exit_with_message("Given PID is invalid!");
	}
}

static void	send_char(const pid_t server_pid, char c)
{
	int	shift_bits;

	shift_bits = 0;
	while (shift_bits < 8)
	{
		if (c & (1 << shift_bits))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		timeout();
		g_success = 0;
		shift_bits++;
		usleep(100);
	}
}

static void	send_msg(const pid_t server_pid, char *msg)
{
	while (*msg)
		send_char(server_pid, *msg++);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	signal(SIGUSR1, signal_handler);
	check_arg(argc, argv);
	server_pid = ft_atoi(argv[1]);
	send_msg(server_pid, argv[2]);
	return (0);
}
