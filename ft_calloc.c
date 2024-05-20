/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:31:02 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 18:12:13 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

// cc -Wall -Wextra -Werror ft_calloc.c ft_bzero.c ft_memset.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

// Fonction de test pour ft_calloc
void test_ft_calloc(size_t count, size_t size, const char *test_description) {
    void *result = ft_calloc(count, size);

    if (result == NULL) {
        printf("Test %s: ft_calloc(%zu, %zu) -> NULL\n", test_description, count, size);
    } else {
        int is_zeroed = 1;
        for (size_t i = 0; i < count * size; i++) {
            if (((unsigned char *)result)[i] != 0) {
                is_zeroed = 0;
                break;
            }
        }

        if (is_zeroed) {
            printf("Test %s: ft_calloc(%zu, %zu) -> Memory is zeroed\n", test_description, count, size);
        } else {
            printf("Test %s: ft_calloc(%zu, %zu) -> Memory is not zeroed\n", test_description, count, size);
        }
    }

    free(result);
}

int main() {
    // Cas de test normaux
    test_ft_calloc(10, sizeof(int), "Normal allocation of 10 integers");
    test_ft_calloc(20, sizeof(char), "Normal allocation of 20 characters");

    // Cas limite
    test_ft_calloc(0, sizeof(int), "Zero allocation with count = 0");
    test_ft_calloc(10, 0, "Zero allocation with size = 0");

    // Cas avec grande allocation (pour tester les limites de la mémoire)
    test_ft_calloc(1000000, sizeof(int), "Large allocation of 1,000,000 integers");

    // Cas où la multiplication de count et size cause un débordement
    test_ft_calloc(SIZE_MAX, 2, "Allocation causing overflow");

    return 0;
}
