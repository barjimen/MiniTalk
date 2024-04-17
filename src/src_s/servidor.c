/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/04/11 20:08:44 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static int	close_s(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

int	write_chr(int pid, char chr)
{
	static char	word[10000];
	static int	i;

	if (chr == '\0')
	{
		ft_putstr_fd(word, 1);
		kill(pid, SIGUSR1);
		pid = 0;
		i = 0;
		ft_bzero(word, ft_strlen(word));
	}
	else
	{
		word[i] = chr;
		i++;
		word[i] = '\0';
	}
	return (pid);
}

static void	signal_handler(int signo, siginfo_t *info, void *n)
{
	static char		chr;
	static int		count;
	static pid_t	pid_c;

	if (signo == SIGINT)
		close_s(MSG_BYE);
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
	sigaction(SIGUSR1, &serv, NULL);
	sigaction(SIGUSR2, &serv, NULL);
	sigaction(SIGINT, &serv, NULL);
	s_msg(0, NULL);
	s_msg(1, numb);
	while (1)
		;
	return (0);
}
