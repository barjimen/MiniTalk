/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:07 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/02 18:47:05 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

int argument_handler(int argc,char **argv)
{
    if (argc != 3)
        exit(EXIT_SUCCESS);
    if (argv[1][0] == 0)
    {
        ft_putendl_fd("No vale 0", 1);
        exit(EXIT_SUCCESS);
    }
    return(1);
}
static void signal_handler(int signo, siginfo_t *info, void *n)
{
    (void) info;
    (void) n;
    
    if(signo == SIGUSR1)
        c_msg(0, NULL);
    else if(signo == SIGUSR2)
        ft_putendl_fd("Ocupado, pruebe más tarde.",1);
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
            {
                printf("no vale ese PID\n");
                exit(EXIT_SUCCESS);
            }        
        }
        else  
            if (kill(pid, SIGUSR2) != 0)
            {
                printf("no vale ese PID\n");
                exit(EXIT_SUCCESS);
            }
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
    pid = ft_atoi(argv[1]);
    if (pid == 0 || argc != 3)
    {
        c_msg(1, NULL);
        exit(0);
    }
    longi = ft_strlen(*argv);
    while (argv[2][count])
    {
        manda_char(pid, argv[2][count]);
        longi--;
        count++;
    }
    manda_char(pid, '\n');
    return(0);
}