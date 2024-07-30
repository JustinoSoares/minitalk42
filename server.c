/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:45:17 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/21 14:16:09 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

void	handle_signal(int sig)
{
	static int	index_bit;
	static char	current_char;

	if (sig == SIGUSR1)
		current_char |= (0b00000001);
	index_bit++;
	if (index_bit == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		index_bit = 0;
		current_char = 0;
	}
	current_char <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID: %d\n", getpid());
	while (1)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_handler = handle_signal;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
