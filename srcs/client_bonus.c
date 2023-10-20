/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:37:34 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/18 23:07:07 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	exit_with_message(char *err_message)
{
	ft_putendl_fd(err_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		exit_with_message("The number of argument is invalid.");
	if (!(*argv[1]))
		exit_with_message("GIven PID is empty.");
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
			exit_with_message("Given PID is invalid.");
	}
	if (*argv[2] == '\0')
		exit_with_message("Given string is empty.");
}

void hoge() {return ;}

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
		shift_bits++;
		usleep(100);
	}
}

static void	send_msg(const pid_t server_pid, char *msg)
{
	while (*msg)
	{
		signal(SIGUSR1, hoge);
		signal(SIGUSR2, hoge);
		send_char(server_pid, *msg++);
	}
}

int main(int argc, char **argv)
{
	pid_t	server_pid;

	check_arg(argc, argv);
	server_pid = ft_atoi(argv[1]);
	send_msg(server_pid, argv[2]);
	return (0);
}
