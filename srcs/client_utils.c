/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:46:01 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/20 20:46:11 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_with_message(char *err_message)
{
	ft_putendl_fd(err_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check_arg(int argc, char **argv)
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
