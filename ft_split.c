/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:55:51 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/22 15:26:31 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void free_split(char **str)
{
	if (!*str)
		return ;
}
 */

int	count_strs(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*str)
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*get_word(char *str, char c)
{
	int		len_word;
	char	*word;

	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len_word + 1);
/* 	i = 0;
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[len_word] = '\0'; */
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		count;
	int		index;
	char	**strings;

	count = count_strs(str, c);
	strings = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
		strings[index++] = get_word(str, c);
			if (!strings[index++])
			{
				while (index--)
					free(strings[index]);
				free(strings);
				return (NULL);
			}
			while (*str && *str != c)
			str++;
		}
		else
			str++;
	}
	strings[index] = NULL;
	return (strings);
}

#include <stdio.h>
int main() {
char **split = ft_split(",,,,coucou, salut,,,,azazaz", ',');
if (split == NULL) {
printf("Erreur Alloc.\n");
return 1;
}
int index = 0;
while (split[index] != NULL) {
printf("%s\n", split[index]);
index++;
}

int i = 0;
while (split[i] != NULL)
{
free(split[i]);
i++;
}
free(split);
return 0;
}

