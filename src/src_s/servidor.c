/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/02/20 20:44:46 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
void signal_handler(int signo)
{
	if (signo == SIGUSR1)
		ft_putstr_fd("1", 1);
	if (signo == SIGUSR2)
		ft_putstr_fd("0", 1);
}
int	main(void)
{
	char *numb;
	pid_t pid;

	pid = getpid();
	numb = ft_itoa(pid);
	ft_putstr_fd("El pid es: ", 1);
	ft_putendl_fd(numb, 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
		;
	return (0);
}