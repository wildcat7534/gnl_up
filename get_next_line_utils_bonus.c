/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:56:11 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/06 23:38:48 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, len + 1);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	int		lentotal;

	lentotal = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * lentotal + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (new_str);
}
*/

char	*ft_strjoin(char *s1, char *s2)
{
    char	*joined;
    size_t	i;
    size_t	j;

    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!joined)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
        joined[j++] = s1[i++];
    i = 0;
    while (s2[i])
        joined[j++] = s2[i++];
    joined[j] = '\0';
    free(s1);
    return (joined);
}