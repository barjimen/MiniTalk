/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:32:22 by barjimen          #+#    #+#             */
/*   Updated: 2022/10/08 23:03:57 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	a;

	a = 0;
	if (!s)
		return ;
	while (s[a])
	{
		f(a, &s[a]);
		a++;
	}
}
