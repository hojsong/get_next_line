/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:14:41 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/20 14:58:57 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	i = -1;
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (0);
	while (++i < len1)
		result[i] = s1[i];
	i = -1;
	while (++i < len2)
		result[i + len1] = s2[i];
	result[i + len1] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	sr;

	sr = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == sr)
			break ;
		i++;
	}
	if (s[i] == '\0' && sr != '\0')
		return (0);
	return ((char *)s + i);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	s_l;
	char	*str;

	s_l = 0;
	while (s[s_l])
		s_l++;
	if (s == NULL)
		return (0);
	if (len <= 0 || s_l < start)
		return (ft_strdup(""));
	s_l = 0;
	while (s[s_l + start])
		s_l++;
	if (s_l < len)
		len = s_l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_s;

	s_s = 0;
	while (src[s_s])
		s_s++;
	if (size == 0)
		return (s_s);
	i = 0;
	while (i + 1 < size && i < s_s)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (s_s);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	i;
	size_t	s_s;

	s_s = 0;
	while (src[s_s])
		s_s++;
	dest = (char *)malloc(sizeof(char) * (s_s + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < s_s)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
