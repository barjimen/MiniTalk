/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_msg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:34:25 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/03 16:27:49 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
void pid_ko()
{
    ft_putendl_fd(MSG_KO, 1);
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
        pid_ko();
    return(1);
}