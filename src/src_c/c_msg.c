/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_msg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:34:25 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/02 18:44:35 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
void pid_0()
{
    ft_putendl_fd(MSG_PID_0, 1);
}

void pid_ok()
{
    ft_putendl_fd(MSG_OK, 1);
}

int c_msg(int numb, char *pid)
{
    (void)pid;
    if(numb == 0)
        pid_ok();
    if(numb == 1)
        pid_0();
    return(1);
}