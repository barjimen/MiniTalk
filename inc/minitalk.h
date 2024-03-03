/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:11:22 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/03 17:08:21 by barjimen         ###   ########.fr       */
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
# define MSG_PID       "El pid es: "
# define MSG_UP        "Running server..."
# define MSG_CLOSE     "Server close, see you!"


//------ ERRORS MSG ------
# define MSG_PID_0     "Invalid PID, write one other than 0!"
# define MSG_PID_ARG   "Invalid argument, try again!"
# define MSG_ARG_3     "Write 3 arguments please."
# define MSG_ARG_0     "Try again writing a PID and a msg"
# define MSG_PID_KO    "Invalid PID!"


#endif
