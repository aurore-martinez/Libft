/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:05:22 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/23 12:00:39 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len_dest;
	size_t	i;

	len_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + ft_strlen(src));
}

/*
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc != 4)
        return (0);
    printf("%u\n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
}
 */
