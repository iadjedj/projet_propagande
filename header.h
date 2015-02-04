/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:14:31 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/04 00:55:25 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# define BUFF_SIZE 2048

int		get_next_line(int const fd, char **line);
int		ft_wstrlen(char *str);
void	censure(char *mot);
#endif