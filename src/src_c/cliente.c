/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:07 by barjimen          #+#    #+#             */
/*   Updated: 2024/02/20 20:29:28 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"


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
    int pid;
    int longi;
    int count;
    
    count = 0;
    (void)argc;
    pid = ft_atoi(argv[1]);
    longi = ft_strlen(*argv);
    while (longi != 0)
    {
        manda_char(pid, argv[2][count]);
        longi--;
        count++;
    }
    //manda_char(pid, '\n');
    return(0);
}