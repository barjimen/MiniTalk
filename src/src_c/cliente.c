/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:07 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/03 17:10:37 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

static int close_c(char *msg)
{
    ft_putendl_fd(msg, 2);
    exit(EXIT_SUCCESS);
}
int argument_handler(int argc,char **argv)
{
    int pid;
    pid = ft_atoi(argv[1]);
    if (!argv[1])
        close_c(MSG_ARG_0);
    if (argc != 3)
        close_c(MSG_ARG_3);
        
    if (pid == 0)
        close_c(MSG_PID_0);
    return(pid);
}
static void signal_handler(int signo, siginfo_t *info, void *n)
{
    (void) info;
    (void) n;
    
    if(signo == SIGUSR1)
        c_msg(0, NULL);
    else if(signo == SIGUSR2)
        c_msg(1, NULL);
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
                close_c(MSG_PID_KO);
        }        
        else  
        {
            if (kill(pid, SIGUSR2) != 0)
                close_c(MSG_PID_KO);
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
    pid = argument_handler(argc, argv);
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