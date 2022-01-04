#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "key_macros.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1080
# define HIGHT 1080
# define TITLE "fdf"

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

//ERROR MESSAGES
# define FDF_INIT_ERR "Fdf initialization error"
# define OPEN_ERR "MAP_FILE ERROR"
# define IMG_INT_ERR "img initialization error"


typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		key_hook(int keycode, t_mlx img);
t_mlx	*fdf_init(void);
void	send_err(char *s);
int draw_line(t_mlx *fdf, int beginX, int beginY, int endX, int endY, int color);
int draw_square(t_mlx *fdf, int beginX, int beginY, int length, int color);
int draw_plain_square(t_mlx *fdf, int beginX, int beginY, int length, int color);
int draw_triangle(t_mlx *fdf, int beginX, int beginY, int height, int color);
int mouse_hook(int button, int x, int y, void *param);
void my_pixel_put(t_mlx *fdf, int x, int y, int color);
#endif