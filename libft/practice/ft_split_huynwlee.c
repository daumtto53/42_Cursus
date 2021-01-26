/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:41:33 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 13:36:14 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t        get_len(char const *s, char c)
{
    size_t        i;
    size_t  cnt;

    i = 0;
    cnt = 0;
    while (*(s + i))
    {
        if (*(s + i) != c)
            ++cnt;
        while (*(s + i) != c && *(s + i))
            ++i;
        if (*(s + i) == c)
            ++i;
    }
    return (cnt);
}

void    str_cpy(char *dst, const char *src, size_t start, size_t end)
{
    size_t  i;

    i = 0;
    while (i < end - start)
    {
        *(dst + i) = *(src + start + i);
        i++;
    }
    *(dst + i) = '\0';
}

char        **ft_split(char const *str, char c)
{
    char        **tmp;
    size_t        len;
    size_t        i;
    size_t        j;
    size_t        k;

    len = get_len(str, c);
    if (!(tmp = (char **)malloc(sizeof(char *) * (len + 1))))
        return (NULL);
    //여기서 문제 발생.
    tmp[len] = '\0';
    //여기서 문제 발생.
    i = 0;
    j = 0;
    while (*(str + i))
    {
        k = i;
        //첫번째 element가 delimiter면 delimiter가 아닌게 나오기 전까지 돌려줌.
        if (*(str + i) == c)
        {
            i++;
            continue;
        }
        while (*(str + i) != c && *(str + i))
            i++;
        if (!(tmp[j] = (char *)malloc(sizeof(char) * (i - k + 1))))
            return (NULL);
        str_cpy(tmp[j++], str, k, i);
    }
    return (tmp);
}
