/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <jsoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:45:06 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/21 12:19:08 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

void	send_bit(pid_t pid, char bit);
void	send_char(pid_t pid, char c);
void	send_mensage(pid_t pid, char *sms);
void	handle_signal(int sig);
int		ft_atoi(char *str);

#endif
