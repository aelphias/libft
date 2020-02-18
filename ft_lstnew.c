/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 02:46:26 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/18 03:12:49 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void const *content, size_t  content_size)
{
    t_list *data;
    
    if (!(data = (t_list *)malloc(sizeof(t_list))))
        return(NULL);
    if (content == NULL)
    {
        data->content = NULL;
        content_size = 0;
    }
    if (!(data->content = (void *)malloc(content_size)))
        return(NULL);
    ft_memcpy(data->content, content, content_size); 
    data->content = (void *)content;
    data->content_size = content_size;
    data->next = NULL;
    return (data);
}