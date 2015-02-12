/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadjedj <iadjedj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 19:20:37 by iadjedj           #+#    #+#             */
/*   Updated: 2015/02/12 10:43:03 by iadjedj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>
# include <mlx.h>
# define BUFF_SIZE	1024

# define ECHAP		65307
# define LEFT		65361
# define UP			65362
# define RIGHT		65363
# define DOWN		65364
# define PLUS		65451
# define MINUS		65453
# define SPACE		32

# pragma pack(push, 1)
typedef struct					s_header
{
	short						signature;
	int							size;
	short						reserved1;
	short						reserved2;
	int							dataoffSet;
	int							bitmapheadersize;
	int							width;
	int							height;
	short						planes;
	short						bitsperpixel;
	int							compression;
	int							sizeImage;
	int							xpixelspremeter;
	int							ypixelspremeter;
	int							colorsused;
	int							colorsimportant;
}								t_header;
# pragma pack(pop)
typedef struct					s_env
{
	void						*mlx;
	void						*win;
	void						*img;
}								t_env;

typedef struct 					s_glitch
{
	t_env						env;
	t_header					header;
	unsigned char				*source;
	unsigned char				*copy;
	int							fd_in;
	int							fd_out;
}								t_glitch;

void			ft_glitch(t_glitch glitch, int equiv_size, int equiv, int noise);
void			data_to_img(t_glitch glitch);
unsigned char	*ft_get_data(const int fd_in, const t_header header);
t_env			start_mlx(t_header header);
int				expose_hook(t_glitch *glitch);
int				key_hook(int keycode, t_glitch *glitch);
void			put_error_and_exit(char *str);
void			clean_exit(t_glitch *glitch);
#endif
