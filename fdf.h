#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "key_macros.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HIGHT 1000
# define TITLE "fdf"

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define INT_MAX 2147483647

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
# define MAP_INIT_ERR "Map initialization error"
# define OPEN_ERR "Open map_file error"
# define MAP_ERR "Map parsing error"
# define USR_ERR "Usage: ./fdf map_file"
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

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
	struct s_point		*next;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	int					z_range;
}						t_map;


int		key_hook(int keycode, t_mlx *fdf);
t_mlx	*fdf_init(void);
t_map	*map_init(void);
void	send_err(char *s);
int		draw_line(t_mlx *fdf, t_point s, t_point f, int color);
int		mouse_hook(int button, int x, int y, t_mlx *fdf);
void	my_pixel_put(t_mlx *fdf, int x, int y, int color);
int		read_map(int fd, t_point **pts_stack, t_map *map);
t_point	*pop_pts(t_point **pts_stack);
void	push_pts(t_point **pts_stack, t_point *new_pts);

#endif