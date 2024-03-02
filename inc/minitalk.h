/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:11:22 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/02 17:29:20 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include "../lib/libft/libft.h"

int c_msg(int numb, char *pid);

//------ MSG for function ------
# define MSG_OK        "Recibido, todo ok."
# define MSG_KO        "Servidor en espera, intentelo de nuevo."

//------ ERRORS for functions ------
# define MSG_PID_0     "Invalid PID, try again!"
# define MSG_PID_ARG   "Invalid argument, try again!"

#endif
