/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:24:58 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/20 20:44:47 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>

void	exit_with_message(char *err_message);
void	check_arg(int argc, char **argv);

#endif