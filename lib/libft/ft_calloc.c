/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:21:24 by barjimen          #+#    #+#             */
/*   Updated: 2023/01/03 18:37:40 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;
	size_t	b;
	size_t	c;

	b = count * size;
	a = (char *) malloc(b);
	if (b < size && b < count)
	{
		return (NULL);
	}
	if (a != NULL)
	{
		c = 0;
		while (c < b)
		{
			a[c] = '\0';
			c++;
		}
	}
	return ((void *)a);
}

/*int	main(void)
{
	char *str[2];

	str[0] = ft_calloc(2, 1);
	str[1] = ft_calloc(2, 1);
	printf("%p\n%p\n", str[0], str[1]);
	str[0] = calloc(2, 1);
	str[1] = calloc(2, 1);
	printf("%p\n%p\n", str[0], str[1]);

	write(1, "hola\n", 5);
	return (1);
}*/
