/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:07 by barjimen          #+#    #+#             */
/*   Updated: 2024/02/27 00:23:44 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static void signal_handler(int signo, siginfo_t *info, void *n)
{
    (void) info;
    (void) n;
    
    if(signo == SIGUSR1)
        ft_putendl_fd("Recibido.", 1);
    else if(signo == SIGUSR2)
        ft_putendl_fd("Ocupado, pruebe más tarde.",1);
    exit(0);
}
void    manda_char(int pid, char ch)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if (ch >> i & 1)
        {
            if (kill(pid, SIGUSR1) != 0)
                exit(EXIT_SUCCESS);
        }
        else  
            if (kill(pid, SIGUSR2) != 0)
                exit(EXIT_SUCCESS);
        i--;
        usleep(300);
    }
}

int main(int argc,char **argv)
{
    struct sigaction client;
    
    int pid;
    int longi;
    int count;
    
    client.sa_flags = SA_SIGINFO;
    client.sa_sigaction = signal_handler;
    sigaction(SIGUSR1,&client, NULL);
    sigaction(SIGUSR2,&client, NULL);
    count = 0;
    (void)argc;
    pid = ft_atoi(argv[1]);
    longi = ft_strlen(*argv);
    while (argv[2][count])
    {
        manda_char(pid, argv[2][count]);
        longi--;
        count++;
    }
    manda_char(pid, '\n');
    //manda_char(pid, '\0');

    return(0);
}