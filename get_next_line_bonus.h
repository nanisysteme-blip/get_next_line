/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtraore <dtraore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:40:10 by dtraore           #+#    #+#             */
/*   Updated: 2026/11/20 23:12:12 by dtraore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <fcntl.h>
#include <unistd.h>

typedef struct s_list{
	int	fd;
	char	*strash;
	struct s_list	*next;
} t_list 

int	get_next_line_bonus(int fd);
char	*ft_strjoin(char *dest, const char *src);
char	*ft_strdup(const char *s);

#endif
