/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:56:20 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:49 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;

    if (!b)
		return (NULL);
    ptr = (unsigned char *)b; // Convertir le pointeur b en un pointeur vers un caractère non signé
    while (len > 0)
    {
        *ptr = (unsigned char)c; // Affecter la valeur c à l'octet pointé par ptr
        ptr++; // Avancer le pointeur vers le prochain octet
        len--; // Décrémenter le nombre d'octets restants
    }
    return b; // Retourner le pointeur vers le début de la mémoire modifiée
} */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char str[10];
    printf("str avant ft_memset: %s\n", str);
    ft_memset(str, 'A', 5);
    // memset(str, 'A', 5);
    printf("str après ft_memset: %s\n", str);
    return 0;
} */
