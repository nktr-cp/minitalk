/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:36:07 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/18 22:00:15 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*必要に応じてatoiを改造する。
*複数送信が死ぬのを直す
*不正なPIDでも動く理由を確かめる
*/

#include "minitalk.h"

static void	signal_handler(int signum)
{
	static int	bit;
	static int	c;

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
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
