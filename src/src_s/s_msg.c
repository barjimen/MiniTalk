/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_msg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:07:08 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/20 20:32:47 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void CL_msg(void)
{
    ft_putendl_fd(MSG_CL, 1);
}

void hi_msg(char *pid)
{
    ft_putendl_fd(MSG_UP, 1);
    ft_putstr_fd(MSG_PID, 1);
    ft_putendl_fd(pid, 1);
}

int s_msg(int numb, char *pid)
{
    if (numb == 0)
        CL_msg();
    if (numb == 1)
        hi_msg(pid);
    return (1);
}
