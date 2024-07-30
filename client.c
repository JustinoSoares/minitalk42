/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:44:50 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/21 13:57:41 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	ft_atoi(char *str)
{
	int	result;
	int	verify;
	int	neg;

	neg = 1;
	verify = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		if (verify)
			return (0);
		verify = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * neg);
}

void	send_bit(pid_t pid, char bit)
{
	if (bit & 0b10000000)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(10);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		send_bit(pid, c & 0b10000000);
		c <<= 1;
	}
}

void	send_mensage(pid_t pid, char *sms)
{
	while (*sms)
	{
		send_char(pid, *sms);
		sms++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		value;

	if (argc != 3)
		return (write(1, "\n", 1));
	value = ft_atoi(argv[1]);
	pid = (pid_t)value;
	send_mensage(pid, argv[2]);
	return (0);
}
