/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/19 20:26:27 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
int	write_chr(int pid, char chr)
{
	static char palabra[10000];
	static int	i;
	
	if (chr == '\0')
	{
		ft_putstr_fd(palabra, 1);
		kill(pid, SIGUSR1);
		pid = 0;
		i = 0;
		ft_bzero(palabra, ft_strlen(palabra));
	}
	else
	{
		palabra[i] = chr;
		i++;
		palabra[i] = '\0';
	}
	return (pid);
}

static void	signal_handler(int signo, siginfo_t *info, void *n)
{
	static char		chr;
	static int		count;
	static pid_t	pid_c;

	if (pid_c == 0)
		pid_c = info->si_pid;
	(void)n;
	if (pid_c != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (signo == SIGUSR1)
		chr = chr | 128 >> count;
	count++;
	if (count == 8)
	{
		pid_c = write_chr(pid_c, chr);
		count = 0;
		chr = 0;
	}
}

int	main(void)
{
	struct sigaction	serv;
	char				*numb;
	pid_t				pid;

	serv.sa_flags = SA_SIGINFO;
	serv.sa_sigaction = signal_handler;
	pid = getpid();
	numb = ft_itoa(pid);
	ft_putstr_fd("El pid es: ", 1);
	ft_putendl_fd(numb, 1);
	sigaction(SIGUSR1, &serv, NULL);
	sigaction(SIGUSR2, &serv, NULL);
	while (1)
		;
	return (0);
}
