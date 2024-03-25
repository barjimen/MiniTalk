/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:11:22 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/20 20:23:58 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	c_msg(int numb, char *pid);
int	s_msg(int numb, char *pid);


//------ MSG for function ------
# define MSG_OK "Recibido, todo ok."
# define MSG_KO "Servidor en espera, intentelo de nuevo."
# define MSG_PID "El pid es: "
# define MSG_UP "Running server... Hello there!"

//------ ERRORS MSG ------
# define MSG_PID_0 "Invalid PID, write one other than 0!"
# define MSG_PID_ARG "Invalid argument, try again!"
# define MSG_ARG_3 "Write 3 arguments please."
# define MSG_ARG_0 "Try again writing a PID and a msg"
# define MSG_PID_KO "Invalid PID!"

//------ OTHER MSG ------
# define MSG_CL "\033[2J\033[1;1H"
# define MSG_BYE "\033[2J\033[1;1H Bye bye!"
#endif
