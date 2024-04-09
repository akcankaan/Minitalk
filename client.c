/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:35:14 by mehakcan          #+#    #+#             */
/*   Updated: 2024/03/25 12:12:11 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

static void	data_transmission(char data, int pid)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < 8)
	{
		if (data << i & 128)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		i++;
		usleep(250);
	}
	if (error == -1)
	{
		ft_putstr("CLIENT PID error : ");
		ft_putstr("Incorrect PID entered\n\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr("CLIENT PID error : ");
			ft_putstr("Incorrect PID entered\n\n");
			exit(1);
		}
		while (av[2][i])
			data_transmission(av[2][i++], pid);
	}
	else
	{
		ft_putstr("CLIENT format error : invalid arguments");
		ft_putstr("Correct format : ./client <PID> <STRING_TO_SEND>");
	}
	return (0);
}
